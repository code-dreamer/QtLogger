#include <QtCore/QCoreApplication>
#include <QTextCodec>

#pragma warning(disable: 4127)

#include "logger/logger.h"
#include "logger/log_level.h"

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

void TestLog()
{
	const qint64 first_lib_id = 0x2a3e2ddb799b6970;
	const char first_lib_id_str[] = "first_lib_id";

	logging::logger* custom_logger = logging::create_logger();
	//custom_logger->set_additional_capture_info( Logging::thread_id_info );

	//ConsoleAppender* consoleAppender = new ConsoleAppender();
	//custom_logger->registerAppender(consoleAppender);

	int i = 0;
	//QString message = QLatin1String("привет");
	QString message = QString::fromAscii("привет");

	const char str[] = "lkdjflskdjflsfg;dfhldhkjlglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfdhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfglkdjflskdjflsfg;dfhldhkjldhfg";

	//for (;;) {
	custom_logger->stream(logging::debug_level, __FILE__, __LINE__, Q_FUNC_INFO) << message << ++i << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << str << "_end";
	//}

	// using custom logger object
	//custom_logger->stream(logging::debug_level, __FILE__, __LINE__, Q_FUNC_INFO) << message << ++i;
	//custom_logger->stream(lib_id, Logging::Debug, __FILE__, __LINE__, Q_FUNC_INFO) << message << ++i;
	//custom_logger->stream(lib_id_str, Logging::Debug, __FILE__, __LINE__, Q_FUNC_INFO) << message << ++i;
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
	QTextCodec::setCodecForCStrings(sourcesEncoding);
	QTextCodec::setCodecForTr(sourcesEncoding);

	TestLog();
	TestLogSingleton();
	
	return a.exec();
}
