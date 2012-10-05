#include "logger/impl/defs_utils.h"
#include "logger/impl/writer_device.h"
#include "logger/impl/log_writer.h"

using namespace logging::impl;

writer_device::writer_device(log_writer* log_writer)
	: QIODevice()
	, log_writer_(log_writer)
	, filename_(nullptr)
	, line_(-1)
	, function_name_(nullptr)
{
	Q_CHECK_PTR(log_writer);
}

writer_device::~writer_device()
{
}

qint64 writer_device::readData(char* UNUSED(data), qint64 UNUSED(maxlen))
{
	Q_ASSERT(false); // not supported
	return 0;
}

qint64 writer_device::writeData(const char* data, qint64 maxSize)
{
	if (maxSize > 0) {
		log_writer_->write(log_Level_, filename_, line_, function_name_, QString::fromLocal8Bit(data, maxSize));
	}
		
	return maxSize;
}

void writer_device::init_write_stage(logging::log_level log_level, const char* filename, int line, const char* function_name)
{	
	if (!QIODevice::isOpen()) {
		QIODevice::open(QIODevice::WriteOnly);
	}

	log_Level_ = log_level;
	filename_ = filename;
	line_ = line;
	function_name_ = function_name;
}
