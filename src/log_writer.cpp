#pragma warning(push, 0)
#include <QDebug>
#pragma warning(pop)

#include "logger/impl/log_writer.h"
#include "logger/impl/writer_device.h"

using namespace Logging::Impl;

log_writer::log_writer()
	: writer_device_( new writer_device() )
{
	if (!writer_device_->isOpen()) {
		writer_device_->open(QIODevice::WriteOnly);
	}
}

log_writer::~log_writer()
{
}

QDebug log_writer::stream()
{
	return QDebug(writer_device_.data());
}
