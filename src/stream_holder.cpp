#include "logger/stream_holder.h"
#include "logger/impl/stream_holder_data.h"

using namespace logging;

stream_holder::stream_holder(const QDebug& stream, delete_handler delete_handler) 
	: data_( new impl::stream_holder_data(stream) )
	, delete_handler_(delete_handler)
{
	data_->ref.ref();
}

stream_holder::stream_holder(const stream_holder& other)
{
	data_ = other.data_;
	data_->ref.ref();

	delete_handler_ = other.delete_handler_;
}

stream_holder::~stream_holder() 
{
	if ( !data_->ref.deref() ) {
		Q_CHECK_PTR(data_);
		delete data_; // this is last reference
		Q_CHECK_PTR(delete_handler_);
		delete_handler_();
	}
}

inline stream_holder::operator QDebug&()
{
	return data_->stream();
}
