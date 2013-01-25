#include "logger/logger.h"
#include "logger/log_level.h"
#include "logger/impl/logger_impl.h"
#include "logger/impl/utils.h"

using namespace logging;

logger::logger()
	: log_impl_( new impl::logger_impl() )
{
}

logger::~logger()
{
}

stream_helper logger::stream_helper(log_level log_level, const char* file, int line, const char* function_name, const char* lib_id)
{
	CHECK_PTR(log_impl_);
	CHECK_CSTRING(function_name);
	CHECK_CSTRING(file);
	ASSERT(line > 0);

	return log_impl_->stream_helper(log_level, file, line, function_name, lib_id);
}

void logger::set_capture_data(logging::capture_type capture_type)
{
	ASSERT(capture_type::no_capture <= capture_type && capture_type < capture_type::invalid);

	log_impl_->set_capture_data(capture_type);
}

bool logger::add_log_writer(log_writer_base* taked_log_writer)
{
	CHECK_PTR(taked_log_writer);

	return log_impl_->add_log_writer(taked_log_writer);
}

void logger::write(const log_info& log_info, const QString& message)
{
	log_impl_->write(log_info, message);
}

void logger::handl_qt_log(bool handle)
{
	log_impl_->handl_qt_log(handle);
}

logger* logging::create_logger()
{
	return new logger();
}
