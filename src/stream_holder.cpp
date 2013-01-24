#include "logger/stream_holder.h"
#include "logger/log_level.h"
#include "logger/impl/log_impl.h"
#include "logger/impl/utils.h"

using namespace logging;

namespace logging {
namespace impl {

struct stream_holder_data
{
	Q_DISABLE_COPY(stream_holder_data)

	stream_holder_data(logging::impl::log_impl* log_writer)
	: stream_(&log_line_)
	, log_writer_(log_writer)
	{}

	~stream_holder_data()
	{
		CHECK_PTR(log_writer_);
		//log_writer_->write(log_Level_, filename_, line_, function_name_, buffer_);
		log_writer_->write(log_info_, log_line_);
	}

	QDebug stream_;
	QString log_line_;

	logging::impl::log_impl* log_writer_;
	/*logging::log_level log_Level_;
	const char* filename_;
	int line_;
	const char* function_name_;*/
	logging::log_info log_info_;
};

} // namespace impl


log_info::log_info()
	: log_level(logging::log_level::debug_level)
	, lib_id(nullptr)
	, filename(nullptr)
	, line(-1)
	, function_name(nullptr)
{}


stream_holder::stream_holder(logging::impl::log_impl* log_writer) 
	: shared_data_( new impl::stream_holder_data(log_writer) )
{
	CHECK_PTR(log_writer);
}

stream_holder::stream_holder(stream_holder& other)
{
	shared_data_ = other.shared_data_;
	other.shared_data_ = nullptr;
}

stream_holder::stream_holder(const stream_holder&& other)
{
	shared_data_ = other.shared_data_;
}

stream_holder& stream_holder::operator=(stream_holder& other)
{
	if (this != &other) {
		shared_data_ = other.shared_data_;
		other.shared_data_ = nullptr;
	}

	return *this;
}

stream_holder::~stream_holder() 
{
	if ( shared_data_ != nullptr ) {
		// this is last reference
		safeDelete(shared_data_);
	}
}

QDebug& stream_holder::out() const
{
	return shared_data_->stream_;
}

log_info& stream_holder::log_info()
{
	return shared_data_->log_info_;
}
/*
void stream_holder::set_log_level(logging::log_level log_level)
{
	shared_data_->log_Level_ = log_level;
}

void stream_holder::set_filename(const char* filename)
{
	shared_data_->filename_ = filename;
}

void stream_holder::set_line(int line)
{
	shared_data_->line_ = line;
}

void stream_holder::set_function_name(const char* function_name)
{
	shared_data_->function_name_ = function_name;
}*/

} // namespace logging