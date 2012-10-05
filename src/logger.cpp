#include "logger/logger.h"
#include "logger/log_level.h"
#include "logger/impl/log_writer_device.h"
#include "logger/impl/log_writer.h"
#include "logger/impl/defs_utils.h"

using namespace logging;

logger::logger()
	: log_writer_( new impl::log_writer() )
{

}

logger::~logger()
{
}

QDebug logger::stream(log_level log_level, const char* file, int line, const char* function)
{
	Q_CHECK_PTR(log_writer_);

	return log_writer_->prepare_stream(log_level, file, line, function);
}

/*
QDebug Logger::stream(qint64 lib_id, const char* file, int line, const char* function)
{

}

QDebug Logger::stream(const char* lib_id_str, const char* file, int line, const char* function)
{

}
*/

void logger::write(log_level log_level, const char* file, int line, const char* function_name, const QString& message)
{
	log_writer_->write(log_level, file, line, function_name, message);
}

logger* logging::create_logger()
{
	return new logger();
}
