#include "logger/impl/defs_utils.h"
#include "logger/impl/writer_device.h"

using namespace logging::impl;

writer_device::writer_device()
	: QIODevice()
{

}

writer_device::~writer_device()
{

}

qint64 writer_device::readData(char* UNUSED(data), qint64 UNUSED(maxlen))
{
	Q_ASSERT(false); // not supported
	return 0;
}

qint64 writer_device::writeData(const char* UNUSED(data), qint64 maxSize)
{
	return maxSize;
}
