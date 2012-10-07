#include "logger/stream_holder.h"
#include "logger/impl/stream_holder_data.h"

using namespace logging;

stream_holder::stream_holder() 
	: data_( new impl::stream_holder_data() )
{
	data_->ref.ref();
}

stream_holder::stream_holder(const stream_holder& other)
{
	data_ = other.data_;
	data_->ref.ref();
}

stream_holder::~stream_holder() 
{
	if ( !data_->ref.deref() ) {
		Q_CHECK_PTR(data_);
		delete data_; // this is last reference
	}
}

QDebug& stream_holder::stream() const
{
	return data_->stream();
}

void stream_holder::set_writer(logging::impl::log_writer* log_writer)
{
	Q_CHECK_PTR(log_writer);
	
	data_->set_writer(log_writer);
}

void stream_holder::set_log_level(logging::log_level log_level)
{
	data_->set_log_level(log_level);
}

void stream_holder::set_filename(const char* filename)
{
	data_->set_filename(filename);
}

void stream_holder::set_line(int line)
{
	data_->set_line(line);
}

void stream_holder::set_function_name(const char* function_name)
{
	data_->set_function_name(function_name);
}
