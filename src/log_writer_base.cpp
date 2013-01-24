#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QString>
#pragma warning(pop)

#include "logger/log_writer_base.h"
#include "logger/impl/utils.h"


namespace logging {

log_writer_base::log_writer_base()
{
}

log_writer_base::~log_writer_base()
{
}

void log_writer_base::write(const QString& log_entry)
{
	CHECK_QSTRING(log_entry);

	QMutexLocker locker(&m_writeMutex);
	do_write(log_entry);
}

} // namespace logging