#include "logger/impl/stream_holder_data.h"
#include "logger/impl/log_writer.h"

using namespace logging::impl;

stream_holder_data::stream_holder_data() 
	: QSharedData()
	, stream_(&buffer_)
{
}

QDebug& stream_holder_data::stream()
{
	return stream_;
}

stream_holder_data::~stream_holder_data()
{
	log_writer_->write(log_Level_, filename_, line_, function_name_, buffer_);
}

void stream_holder_data::set_writer(logging::impl::log_writer* log_writer)
{
	log_writer_ = log_writer;
}

void stream_holder_data::set_log_level(logging::log_level log_level)
{
	log_Level_ = log_level;
}

void stream_holder_data::set_filename(const char* filename)
{
	filename_ = filename;
}

void stream_holder_data::set_line(int line)
{
	line_ = line;
}

void stream_holder_data::set_function_name(const char* function_name)
{
	function_name_ = function_name;
}
