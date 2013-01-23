#include "logger/stream_holder.h"
#include "logger/log_level.h"
#include "logger/impl/log_writer.h"
#include "logger/impl/utils.h"

using namespace logging;

namespace logging {
namespace impl {

struct stream_holder_data
{
	Q_DISABLE_COPY(stream_holder_data)

	stream_holder_data(logging::impl::log_writer* log_writer)
	: stream_(&buffer_)
	, log_writer_(log_writer)
	, log_Level_(logging::log_level::debug_level)
	, filename_(nullptr)
	, line_(-1)
	, function_name_(nullptr)
	{}

	~stream_holder_data()
	{
		CHECK_PTR(log_writer_);
		log_writer_->write(log_Level_, filename_, line_, function_name_, buffer_);
	}

	QDebug stream_;
	QString buffer_;

	logging::impl::log_writer* log_writer_;
	logging::log_level log_Level_;
	const char* filename_;
	int line_;
	const char* function_name_;
};

} // namespace impl
} // namespace logging


stream_holder::stream_holder(logging::impl::log_writer* log_writer) 
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

QDebug& stream_holder::stream() const
{
	return shared_data_->stream_;
}

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
}
