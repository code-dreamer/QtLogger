#pragma once

#include "logger/log_writer_base.h"

namespace logging {
;
class LOGGER_EXPORT debug_writer : public log_writer_base
{
	Q_DISABLE_COPY(debug_writer)

public:
	debug_writer();
	virtual ~debug_writer();

protected:
	virtual void do_write(const QString& log_entry);
};

} // namespace logging
