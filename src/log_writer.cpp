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

	if (!writer_device_->isOpen()) {
		writer_device_->open(QIODevice::WriteOnly);
	}
}

log_writer::~log_writer()
{
}

/*
QDebug log_writer::stream()
{
	return QDebug(writer_device_.data());
}*/

QDebug log_writer::prepare_stream(logging::log_level log_level, const char* filename, int line, const char* function)
{
	Q_ASSERT(writer_device_->isOpen());

	writer_device_->set_log_info(log_level, filename, line, function);
	return QDebug(writer_device_.data());
}

void log_writer::write(logging::log_level log_level, const char* file, int line, const char* function_name, const QString& message)
{
	//write to appenders
}