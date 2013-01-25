#include "logger/stream_helper.h"
#include "logger/log_level.h"
#include "logger/impl/logger_impl.h"
#include "logger/impl/utils.h"

namespace logging {
namespace impl {

struct stream_holder_data
{
	Q_DISABLE_COPY(stream_holder_data)

	stream_holder_data(logging::impl::logger_impl* log_writer)
	: stream_(&log_line_)
	, log_writer_(log_writer)
	{}

	~stream_holder_data()
	{
		CHECK_PTR(log_writer_);
		log_writer_->write(log_info_, log_line_);
	}

	QDebug stream_;
	QString log_line_;

	logging::impl::logger_impl* log_writer_;
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


stream_helper::stream_helper(logging::impl::logger_impl* log_writer) 
	: shared_data_( new impl::stream_holder_data(log_writer) )
{
	CHECK_PTR(log_writer);
}

stream_helper::stream_helper(stream_helper& other)
{
	shared_data_ = other.shared_data_;
	other.shared_data_ = nullptr;
}

stream_helper::stream_helper(const stream_helper&& other)
{
	shared_data_ = other.shared_data_;
}

stream_helper& stream_helper::operator=(stream_helper& other)
{
	if (this != &other) {
		shared_data_ = other.shared_data_;
		other.shared_data_ = nullptr;
	}

	return *this;
}

stream_helper::~stream_helper() 
{
	if ( shared_data_ != nullptr ) {
		// this is last reference
		safeDelete(shared_data_);
	}
}

QDebug& stream_helper::stream() const
{
	return shared_data_->stream_;
}

log_info& stream_helper::log_info()
{
	return shared_data_->log_info_;
}

} // namespace logging