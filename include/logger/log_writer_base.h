#pragma once

#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QMutex>
#pragma warning(pop)

#include "logger/logger_lib_switch.h"

class QString;

namespace logging {
;
enum class log_level;

class LOGGER_EXPORT log_writer_base
{
	Q_DISABLE_COPY(log_writer_base)

public:
	log_writer_base();
	virtual ~log_writer_base();

public:
    void write(const QString& log_entry);

protected:
	virtual void do_write(const QString& log_entry) = 0;

private:
	QMutex m_writeMutex;
};

} // namespace logging
