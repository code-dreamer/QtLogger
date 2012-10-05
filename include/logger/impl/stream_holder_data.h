#pragma once

#pragma warning(push, 0)
#include <QSharedData>
#include <QDebug>
#pragma warning(pop)

#include "logger/log_level.h"

namespace logging
{
namespace impl
{

class stream_holder_data : public QSharedData
{
	Q_DISABLE_COPY(stream_holder_data)

public:
	stream_holder_data(const QDebug& stream);

public:
	QDebug& stream();

private:
	QDebug stream_;
};

} // impl
} // logging