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
	log_info& log_info = stream_holder.log_info();
	log_info.log_level = log_level;
	log_info.filename = filename;
	log_info.line = line;
	log_info.function_name = function_name;

	return stream_holder;
}

logging::stream_holder log_writer::make_stream(logging::log_level log_level, const char* module_id, const char* filename, int line, const char* function_name)
{
	stream_holder stream_holder(this);
	log_info& log_info = stream_holder.log_info();
	log_info.module_id = module_id;
	log_info.log_level = log_level;
	log_info.filename = filename;
	log_info.line = line;
	log_info.function_name = function_name;

	return stream_holder;
}

void log_writer::write(const logging::log_info& log_info, const QString& message)
{
	//write to appenders

	Q_UNUSED(log_info);
	Q_UNUSED(message);
}
