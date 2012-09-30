#pragma once

#pragma warning(push, 0)
#include <QScopedPointer>
#pragma warning(pop)

namespace logging
{
namespace impl
{

class writer_device;

class log_writer
{
public:
	log_writer();
	~log_writer();

public:
	QDebug stream();

private:
	QScopedPointer<writer_device> writer_device_;
};

} // impl
} // logging