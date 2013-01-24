#pragma warning(push, 0)
#pragma warning(disable: 4350)
#pragma warning(disable: 4127)
#include <QtCore/QCoreApplication>
#include <QTextCodec>
#include <QDateTime>
#pragma warning(pop)

//#pragma warning(disable: 4127)

#include "logger/logger.h"
#include "logger/log_level.h"
#include "logger/file_log_writer.h"
#include "logger/debug_writer.h"

void TestLogSingleton()
{/*
	const qint64 first_lib_id = 0x2a3e2ddb799b6970;
	const char first_lib_id_str[] = "first_lib_id";

	ConsoleAppender* consoleAppender = new ConsoleAppender();
	Logging::set_additional_capture_info( Logging::thread_id_info );
	Logging::registerAppender(consoleAppender);

	int i = 0;
	QString message = "message";

	// using internal singleton
	Logging::stream(Logging::Debug, __FILE__, __LINE__, Q_FUNC_INFO) << message << ++i;
	Logging::stream(lib_id, Logging::Debug, __FILE__, __LINE__, Q_FUNC_INFO) << message << ++i;
	Logging::stream(lib_id_str, Logging::Debug, __FILE__, __LINE__, Q_FUNC_INFO) << message << ++i;*/
}
/*
QDebug operator<<(QDebug d, const QVariant & v)
{
	return d.space() << v;
}*/

/*
QDebug& operator<<(QDebug dbg, const QString &v)
{
	return dbg.operator<<(v);
}*/

/*
QDebug& operator<<(logging::stream_holder& stream_holder, const QString& t)
{
	return qDebug();
}*/

void TestLog()
{
	QString s;
	QDebug deb1(&s);
	QString testm = QLatin1String("asdasd");
	deb1 << testm;

	const qint64 first_lib_id = 0x2a3e2ddb799b6970;
	const char first_lib_id_str[] = "first_lib_id";

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

	//console_writer* console_writer = new console_writer();
	//custom_logger->addWriter(console_writer);

	QString message = QTextCodec::codecForLocale()->toUnicode("привет");
	
	const char str[] = "lkdjflskdjflsfg;dfhldhkjlglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfdhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfg";

	int val = 123;
	//custom_logger->make_stream(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO).stream() << message << message << 123;
	custom_logger->make_stream(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO).out() << "val =" << 123 << message;
	custom_logger->make_stream(logging::log_level::warning_level, __FILE__, __LINE__, Q_FUNC_INFO, first_lib_id_str).out() << "val =" << 123 << message;
	//custom_logger->make_stream(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO) << message << message;
}

/*
const qint64 first_lib_id = 0x2a3e2ddb799b6970;
const char first_lib_id_str[] = "first_lib_id";

const qint64 second_lib_id = 0x06567fbb4dcb9584;
const char second_lib_id_str[] = "second_lib_id";
*/

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QTextCodec* const sourcesEncoding = QTextCodec::codecForLocale(); // assume that sources have system locale
	//QTextCodec::setCodecForCStrings(sourcesEncoding);
	//QTextCodec::setCodecForTr(sourcesEncoding);

	TestLog();
	TestLogSingleton();
	
	return a.exec();
}
