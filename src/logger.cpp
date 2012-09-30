#include "logger/logger.h"
#include "logger/log_level.h"
#include "logger/impl/log_writer_device.h"
#include "logger/impl/log_writer.h"
#include "logger/impl/defs_utils.h"

using namespace Logging;

Logger::Logger()
	: log_writer_( new Impl::log_writer() )
{

}

Logger::~Logger()
{
}

QDebug Logger::stream(LogLevel UNUSED(logLevel), const char* UNUSED(file), int UNUSED(line), const char* UNUSED(function))
{
	Q_CHECK_PTR(log_writer_);
	return log_writer_->stream();
}

/*
QDebug Logger::stream(qint64 lib_id, const char* file, int line, const char* function)
{

}

QDebug Logger::stream(const char* lib_id_str, const char* file, int line, const char* function)
{

}
*/

Logger* Logging::create_logger()
{
	return new Logger();
}
