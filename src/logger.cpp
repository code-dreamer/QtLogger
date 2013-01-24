#include "logger/logger.h"
#include "logger/log_level.h"
#include "logger/impl/log_writer_device.h"
#include "logger/impl/log_writer.h"
#include "logger/impl/utils.h"

using namespace logging;

logger::logger()
	: log_writer_( new impl::log_writer() )
{
}

logger::~logger()
{
}

stream_holder logger::make_stream(log_level log_level, const char* file, int line, const char* function_name, const char* lib_id)
{
	CHECK_PTR(log_writer_);
	CHECK_CSTRING(function_name);
	CHECK_CSTRING(file);
	ASSERT(line > 0);

	return log_writer_->make_stream(log_level, file, line, function_name, lib_id);
}

void logger::set_capture_data(logging::capture_type capture_type)
{
	ASSERT(capture_type::no_capture <= capture_type && capture_type < capture_type::invalid);

	log_writer_->set_capture_data(capture_type);
}

/*
QDebug Logger::stream(qint64 lib_id, const char* file, int line, const char* function)
{

}

QDebug Logger::stream(const char* lib_id_str, const char* file, int line, const char* function)
{

}
*/

void logger::write(const log_info& log_info, const QString& message)
{
	log_writer_->write(log_info, message);
}

logger* logging::create_logger()
{
	return new logger();
}
