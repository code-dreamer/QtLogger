#pragma warning(push, 0)
#include <QDebug>
#pragma warning(pop)

#include "logger/impl/log_writer.h"
#include "logger/impl/writer_device.h"
#include "logger/log_level.h"

using namespace logging::impl;

log_writer::log_writer()
{
	writer_device_.reset(new writer_device(this));
}

log_writer::~log_writer()
{
}

/*
QDebug log_writer::stream()
{
	return QDebug(writer_device_.data());
}*/

logging::stream_holder log_writer::prepare_stream(logging::log_level log_level, const char* filename, int line, const char* function_name)
{
	write_stage_guarder_.lock();

	writer_device_->init_write_stage(log_level, filename, line, function_name);

	return stream_holder( QDebug(writer_device_.data()), [&]() {
		write_stage_guarder_.unlock();
	} );
}

void log_writer::write(logging::log_level log_level, const char* file, int line, const char* function_name, const QString& message)
{
	//write to appenders
}