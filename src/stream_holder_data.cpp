#include "logger/impl/stream_holder_data.h"

using namespace logging::impl;

stream_holder_data::stream_holder_data(const QDebug& stream) 
	: QSharedData()
	, stream_(stream)
{
}

QDebug& stream_holder_data::stream()
{
	return stream_;
}
