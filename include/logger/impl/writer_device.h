#pragma once

#pragma warning(push, 0)
#include <QIODevice>
#pragma warning(pop)

#include "logger/log_level.h"

namespace logging
{
namespace impl
{

class log_writer;

class writer_device : public QIODevice
{
	Q_DISABLE_COPY(writer_device);

public:
	writer_device(log_writer* log_writer);
	virtual ~writer_device();

public:
	void init_write_stage(logging::log_level log_level, const char* filename, int line, const char* function_name);

protected:
	virtual qint64 readData(char*, qint64) override;
	virtual qint64 writeData(const char* data, qint64 maxSize);

private:
	log_writer* log_writer_;

	logging::log_level log_Level_;
	const char* filename_;
	int line_;
	const char* function_name_;
};

} // impl
} // logging