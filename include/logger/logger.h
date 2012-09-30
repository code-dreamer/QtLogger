#pragma once

#include <QObject>

#include "logger/impl/logger_lib_switch.h"


namespace Logging
{

enum LogLevel;

class LOGGER_EXPORT Logger
{
	Q_DISABLE_COPY(Logger)
	
public:
	Logger();
	~Logger();

public:
	//QDebug stream(LogLevel logLevel, const char* file, int line, const char* function);
	//QDebug stream(qint64 lib_id, const char* file, int line, const char* function);
	//QDebug stream(const char* lib_id_str, const char* file, int line, const char* function);
};

} // Logging
