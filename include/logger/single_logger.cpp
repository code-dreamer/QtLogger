#pragma once

#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QMutex>
#include <QScopedPointer>
#include <QStringList>
#pragma warning(pop)

#include "logger/single_logger.h"

namespace logging {
namespace {
	QScopedPointer<logger> global_logger;
	QMutex logger_mutex;
}

logger* single_logger()
{
	QMutexLocker locker(&logger_mutex);
	
	if (global_logger.isNull()) {
		global_logger.reset( create_logger() );
	}
	
	return global_logger.data();
}

} // namespace logging
