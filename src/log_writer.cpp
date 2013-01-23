#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QDebug>
#pragma warning(pop)

#include "logger/impl/log_writer.h"
#include "logger/log_level.h"

using namespace logging::impl;

log_writer::log_writer()
{
}

log_writer::~log_writer()
{
}

logging::stream_holder log_writer::make_stream(logging::log_level log_level, const char* filename, int line, const char* function_name)
{
	stream_holder stream_holder(this);
	stream_holder.set_log_level(log_level);
	stream_holder.set_filename(filename);
	stream_holder.set_line(line);
	stream_holder.set_function_name(function_name);

	return stream_holder;
}

void log_writer::write(logging::log_level log_level, const char* file, int line, const char* function_name, const QString& message)
{
	//write to appenders

	Q_UNUSED(log_level);
	Q_UNUSED(file);
	Q_UNUSED(line);
	Q_UNUSED(function_name);
	Q_UNUSED(message);
}
