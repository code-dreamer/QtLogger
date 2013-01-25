#pragma once

#pragma warning(push, 0)
#include <QScopedPointer>
#include <QReadWriteLock>
#pragma warning(pop)

#include "logger/stream_helper.h"

namespace logging {

enum class capture_type;
class log_writer_base;

namespace impl {

class logger_impl
{
	Q_DISABLE_COPY(logger_impl);

public:
	logger_impl();
	~logger_impl();

public:
	void set_capture_data(capture_type capture_type);
	stream_helper stream_helper(log_level log_level, const char* file, int line, const char* function_name, const char* lib_id = nullptr);
	void write(const logging::log_info& log_info, const QString& message);
	bool add_log_writer(log_writer_base* taked_log_writer);

	void handl_qt_log(bool handle);

private:
	//capture_type capture_type_;
	QList<log_writer_base*> log_writers_;
	QReadWriteLock log_writers_lock_;
	QtMessageHandler prev_qt_log_handler_;
};

} // namespace impl
} // namespace logging