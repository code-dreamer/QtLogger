#pragma once

#pragma warning(push, 0)
#include <QScopedPointer>
#include <QMutex>
#pragma warning(pop)

#include "logger/log_level.h"
#include "logger/stream_holder.h"

namespace logging
{
namespace impl
{

class writer_device;

class log_writer
{
	Q_DISABLE_COPY(log_writer);

public:
	log_writer();
	~log_writer();

public:
	logging::stream_holder make_stream(logging::log_level log_level, const char* filename, int line, const char* function_name);
	logging::stream_holder make_stream(log_level log_level, const char* module_id, const char* file, int line, const char* function_name);
	
	void write(const logging::log_info& log_info, const QString& message);
	//void write(log_level log_level, const char* file, int line, const char* function_name, const QString& message);
};

} // impl
} // logging