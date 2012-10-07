#pragma once

#pragma warning(push, 0)
#include <QObject>
#include <QDebug>
#pragma warning(pop)

#include "logger/impl/logger_lib_switch.h"
#include "logger/stream_holder.h"

namespace logging
{

enum log_level;

namespace impl
{
class log_writer;
}

class LOGGER_EXPORT logger
{
	Q_DISABLE_COPY(logger)
	
	friend LOGGER_EXPORT logger* create_logger();
	
public:
	~logger();
private:
	logger();

public:
	stream_holder make_stream(log_level log_level, const char* file, int line, const char* function_name);
	//QDebug stream(qint64 lib_id, const char* file, int line, const char* function);
	//QDebug stream(const char* lib_id_str, const char* file, int line, const char* function);
	void write(log_level log_level, const char* file, int line, const char* function_name, const QString& message);
	
#pragma warning(push)
#pragma warning(disable : 4251)
private:
	QScopedPointer<impl::log_writer> log_writer_;
#pragma warning(pop)
};

LOGGER_EXPORT logger* create_logger();

} // logging
