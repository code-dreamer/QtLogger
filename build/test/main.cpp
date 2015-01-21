#pragma warning(push, 0)
#pragma warning(disable: 4350)
#pragma warning(disable: 4127)
#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include <QDateTime>

#include "logger/logger.h"
#include "logger/log_level.h"
#include "logger/file_log_writer.h"
#include "logger/debug_writer.h"
#include "logger/single_logger.h"
#pragma warning(pop)

// use internal singleton
//
void TestLogSingleton()
{
	const char first_lib_id_str[] = "first_lib_id";

	logging::debug_writer* debug_writer = new logging::debug_writer();
	logging::single_logger()->add_log_writer(debug_writer);
	logging::single_logger()->handl_qt_log(true);

	logging::single_logger()->set_log_level(logging::log_level::warning_level);

	LOG_DEBUG() << "val =" << 111;
	LIB_LOG_DEBUG(first_lib_id_str) << "val =" << 123;

	LOG_WARNING() << "val =" << 222;
	logging::single_logger()->set_log_level(logging::log_level::critical_level);
	LOG_WARNING() << "val =" << 333;
	//logging::single_logger()->stream_helper(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO).stream() << "val =" << 123;
}

void TestLog()
{
	logging::logger* custom_logger = logging::create_logger();
	logging::file_log_writer* file_log = new logging::file_log_writer(QLatin1String("test_log.txt"));
	logging::debug_writer* debug_writer = new logging::debug_writer();
	custom_logger->add_log_writer(file_log);
	custom_logger->add_log_writer(debug_writer);
	/*custom_logger->set_log_level(logging::log_level::debug_level);
	custom_logger->set_log_level(first_lib_id, logging::log_level::debug_level);
	custom_logger->set_additional_capture_info(logging::line | logging:: logging::thread_id Logging::proc_id | Logging::thread_id );

	ConsoleAppender* consoleAppender = new ConsoleAppender();
	custom_logger->registerAppender(consoleAppender);
	custom_logger->registerAppender(first_lib_id, consoleAppender);
	custom_logger->registerAppender(logging::log_level::info_level, consoleAppender);
	custom_logger->registerAppender(first_lib_id, logging::log_level::info_level | logging::log_level::warning_level, consoleAppender);
	*/

	const char first_lib_id_str[] = "first_lib_id";
//	const char str[] = "lkdjflskdjflsfg;dfhldhkjlglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfdhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfg";

	QString message = QTextCodec::codecForLocale()->toUnicode("привет");
	//custom_logger->make_stream(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO).stream() << message << message << 123;
	custom_logger->stream_helper(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO).stream() << "val =" << 111 << message;
	custom_logger->stream_helper(logging::log_level::warning_level, __FILE__, __LINE__, Q_FUNC_INFO, first_lib_id_str).stream() << "val =" << 222 << message;

	//custom_logger->make_stream(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO) << message << message;
}

int main(int argc, char *argv[])
{
	QCoreApplication app(argc, argv);

	//QTextCodec* const sourcesEncoding = QTextCodec::codecForLocale(); // assume that sources have system locale
	//QString ss = sourcesEncoding->toUnicode("тест");
	
	//TestLog();
	TestLogSingleton();
	
	return EXIT_SUCCESS;
}
