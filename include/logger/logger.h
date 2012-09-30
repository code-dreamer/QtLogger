#pragma once

#pragma warning(push, 0)
#include <QObject>
#include <QDebug>
#pragma warning(pop)

#include "logger/impl/logger_lib_switch.h"

namespace Logging
{

enum LogLevel;

namespace Impl
{
class log_writer;
}

class LOGGER_EXPORT Logger
{
	Q_DISABLE_COPY(Logger)
	
	friend LOGGER_EXPORT Logger* create_logger();
	
public:
	~Logger();
private:
	Logger();

public:
	QDebug stream(LogLevel logLevel, const char* file, int line, const char* function);
	//QDebug stream(qint64 lib_id, const char* file, int line, const char* function);
	//QDebug stream(const char* lib_id_str, const char* file, int line, const char* function);
	
#pragma warning(push)
#pragma warning(disable : 4251)
private:
	QScopedPointer<Impl::log_writer> log_writer_;
#pragma warning(pop)
};

LOGGER_EXPORT Logger* create_logger();

} // Logging
