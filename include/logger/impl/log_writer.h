#pragma once

#pragma warning(push, 0)
#include <QScopedPointer>
#pragma warning(pop)

#include "logger/log_level.h"

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
	//QDebug stream();
	QDebug prepare_stream(logging::log_level log_level, const char* filename, int line, const char* function);
	
	void write(log_level log_level, const char* file, int line, const char* function_name, const QString& message);

private:
	QScopedPointer<writer_device> writer_device_;
};

} // impl
} // logging