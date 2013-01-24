#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QDebug>
#include <QStringList>
#pragma warning(pop)

#include "logger/log_level.h"
#include "logger/log_level.h"
#include "logger/capture_type.h"
#include "logger/impl/log_writer.h"
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

	if (log_info.lib_id != nullptr) {
		out << log_info.lib_id << _S(" ");
	}

	if (log_info.function_name != nullptr) {
		out << log_info.function_name << _S(" ");
	}

	if (log_info.filename != nullptr) {
		out << log_info.filename << _S(" ");
	}

	if (log_info.line >= 0) {
		out << _S(":") << log_info.line;
	}

	if (!log_info.captured_data.isEmpty()) {
		// write captured data
	}

	out << endl;

	return entry;
}
} // namespace


log_writer::log_writer()
	: capture_type_(capture_type::no_capture)
{
}

log_writer::~log_writer()
{
}

logging::stream_holder log_writer::make_stream(log_level log_level, const char* filename, int line, const char* function_name, const char* lib_id)
{
	stream_holder stream_holder(this);
	log_info& log_info = stream_holder.log_info();
	log_info.time_stamp = QDateTime::currentDateTime();
	log_info.lib_id = lib_id;
	log_info.log_level = log_level;
	log_info.filename = filename;
	log_info.line = line;
	log_info.function_name = function_name;
	log_info.captured_data = capture_data(capture_type_);

	return stream_holder;
}

void log_writer::set_capture_data(logging::capture_type capture_type)
{
	capture_type_ = capture_type;
}

void log_writer::write(const log_info& log_info, const QString& message)
{
	QString log_entry = formate_log_entry(log_info, message);

	//write to appenders
}
