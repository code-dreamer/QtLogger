#pragma once

#include <QObject>

#include "logger/impl/logger_lib_switch.h"

namespace Logging
{

class LOGGER_EXPORT Logger : public QObject
{
	Q_OBJECT

public:
	Logger();
	virtual ~Logger();
};

} // Logging
