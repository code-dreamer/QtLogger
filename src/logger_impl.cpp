#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QDebug>
#include <QStringList>
#include <QtGlobal>
#pragma warning(pop)

#include "logger/log_level.h"
#include "logger/stream_helper.h"
#include "logger/capture_type.h"
#include "logger/log_writer_base.h"
#include "logger/impl/logger_impl.h"
#include "logger/impl/utils.h"
#include "logger/impl/bit_tools.h"

using namespace logging;
using namespace logging::impl;

namespace {
QString capture_data(capture_type capture_type)
{
	QString result;

	if (bit_tools::check_bit((int)capture_type, (int)capture_type::proc_id)) {
		QTextStream stream(&result);
		stream << QLatin1String("proc_id = ") 
			<< QLatin1String("[") << QLatin1String("not implemented") << QLatin1String("]");
	}

	if (bit_tools::check_bit((int)capture_type, (int)capture_type::thread_id)) {
		QTextStream stream(&result);
		stream << QLatin1String("; thread_id = ") 
			<< QLatin1String("[") << QLatin1String("not implemented") << QLatin1String("]");
	}

	return result;
}

QString log_level_to_qstring(logging::log_level level)
{
	ASSERT(log_level::debug_level <= level && level < log_level::invalid_level);

	QString level_str;

	switch (level) {
	case log_level::debug_level:
		level_str = _S("DEBUG");
		break;
	
	case log_level::info_level:
		level_str = _S("INFO");
		break;
	
	case log_level::warning_level:
		level_str = _S("WARNING");
		break;
	
	case log_level::error_level:
		level_str = _S("ERROR");
		break;
	
	case log_level::critical_level:
		level_str = _S("CRITICAL");
		break;
	
	case log_level::fatal_level:
		level_str = _S("FATAL");
		break;

	case log_level::invalid_level:
	default:
		ASSERT(false);
		level_str = _S("LOG INTERNAL ERROR");
		break;
	}

	return level_str;
}

QString formate_log_entry(const log_info& log_info, const QString& message)
{
	QDateTime time_stamp = QDateTime::currentDateTime();
	QString entry = time_stamp.date().toString(Qt::SystemLocaleShortDate);
	QTextStream out(&entry);
	out << endl << time_stamp.time().toString(_S("hh:mm:ss.zzz "));

	out << log_level_to_qstring(log_info.log_level) << _S(": ");

	QStringList lines = entry.split(_S("\n"));
	int indent_len = lines.last().length();

	out << message << endl;

	QString indent_str;
	for (int i = 0; i < indent_len; ++i) {
		indent_str.push_back(_S(" "));
	}
	out << indent_str;

	QString source_info;
	QTextStream source_info_out(&source_info);

	if (log_info.lib_id != nullptr) {
		source_info_out << log_info.lib_id;
	}

	if (log_info.function_name != nullptr) {
		if (!source_info.isEmpty()) {
			source_info_out << _S(", ");
		}
		source_info_out << log_info.function_name;
	}

	if (log_info.filename != nullptr) {
		if (!source_info.isEmpty()) {
			source_info_out << _S(", ");
		}

		QString file_info = _S(log_info.filename);
		if (log_info.line >= 0) {
			file_info.push_back( QString(_S(": %1")).arg(log_info.line) );
		}

		source_info_out << file_info;
	}

	if (!log_info.captured_data.isEmpty()) {
		// write captured data
	}

	out << source_info << endl;

	return entry;
}

logging::impl::logger_impl* qt_log_writer = nullptr;

void qt_message_handler(QtMsgType type, const QMessageLogContext& message_context, const QString& message)
{
	log_info log_info;
	log_info.time_stamp = QDateTime::currentDateTime();
	log_info.lib_id = "Qt " QT_VERSION_STR;
	log_info.filename = message_context.file;
	log_info.line = message_context.line;
	log_info.function_name = message_context.function;

	switch (type) {
	case QtDebugMsg:
		log_info.log_level = log_level::debug_level;
		break;
	case QtWarningMsg:
		log_info.log_level = log_level::warning_level;
		break;
	case QtCriticalMsg:
		log_info.log_level = log_level::critical_level;
		break;
	case QtFatalMsg:
		log_info.log_level = log_level::fatal_level;
		break;
	default:
		ASSERT(false);
	}

	CHECK_PTR(qt_log_writer);
	if (qt_log_writer != nullptr) {
		qt_log_writer->write(log_info, message);
	}
}

} // namespace


logger_impl::logger_impl()
	//: capture_type_(capture_type::no_capture)
	: prev_qt_log_handler_(nullptr)
	, curr_log_level_(log_level::info_level)
{
}

logger_impl::~logger_impl()
{
	// cleanup writers
	QReadLocker appenders_locker(&log_writers_lock_);
	foreach (log_writer_base* log_writer, log_writers_) {
		safeDelete(log_writer);
	}

	handl_qt_log(false);
}

stream_helper logger_impl::stream_helper(log_level log_level, const char* filename, int line, const char* function_name, const char* lib_id)
{
	logging::stream_helper stream_helper(this);
	log_info& log_info = stream_helper.log_info();
	log_info.time_stamp = QDateTime::currentDateTime();
	log_info.lib_id = lib_id;
	log_info.log_level = log_level;
	log_info.filename = filename;
	log_info.line = line;
	log_info.function_name = function_name;
	//log_info.captured_data;// = capture_data(capture_type_);

	return stream_helper;
}

void logger_impl::set_capture_data(logging::capture_type capture_type)
{
	ASSERT(false); // not implemented yet
	Q_UNUSED(capture_type);
	//capture_type_ = capture_type;
}

void logger_impl::write(const log_info& log_info, const QString& message)
{
	// ignore log messages with level lower than current
	if (log_info.log_level < curr_log_level_) {
		return;
	}

	const QString log_entry = formate_log_entry(log_info, message);

	QReadLocker locker(&log_writers_lock_);

	foreach (log_writer_base* log_writer, log_writers_) {
		log_writer->write(log_entry);
	}

	if (log_info.log_level == log_level::fatal_level) {
		abort();
	}
}

bool logger_impl::add_log_writer(log_writer_base* taked_log_writer)
{
	QWriteLocker locker(&log_writers_lock_);

	if (!log_writers_.contains(taked_log_writer)) {
		log_writers_.append(taked_log_writer);
		return true;
	}

	return false;
}

void logger_impl::handl_qt_log(bool handle)
{
	if (handle) {
		qt_log_writer = this;
		prev_qt_log_handler_ = qInstallMessageHandler(qt_message_handler);
	}
	else if (qt_log_writer == this) {
		qInstallMessageHandler(prev_qt_log_handler_);
		prev_qt_log_handler_ = nullptr;
		qt_log_writer = nullptr;
	}
}

void logger_impl::set_log_level(log_level log_level)
{
	curr_log_level_ = log_level;
}
