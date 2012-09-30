#pragma once

#pragma warning(push, 0)
#include <QScopedPointer>
#pragma warning(pop)

namespace Logging
{
namespace Impl
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

} // Impl
} // Logging