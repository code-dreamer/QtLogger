#pragma once

#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QObject>
#include <QDebug>
#pragma warning(pop)

#include "logger/logger_lib_switch.h"
#include "logger/stream_helper.h"
#include "logger/capture_type.h"


namespace logging {
enum class log_level;
enum class capture_type;

class log_writer_base;

namespace impl {
class logger_impl;
} // namespace impl


class LOGGER_EXPORT logger
{
	Q_DISABLE_COPY(logger)
	
	friend LOGGER_EXPORT logger* create_logger();
	
public:
	~logger();
private:
	logger();

public:
	void set_capture_data(logging::capture_type capture_type);
	stream_helper stream_helper(log_level log_level, const char* file, int line, const char* function_name, const char* lib_id = nullptr);
	bool add_log_writer(log_writer_base* taked_log_writer);

	void handl_qt_log(bool handle);

	void set_log_level(log_level log_level);

private:
	void write(const log_info& log_info, const QString& message);
	
#pragma warning(push)
#pragma warning(disable : 4251)
private:
	QScopedPointer<impl::logger_impl> log_impl_;
#pragma warning(pop)
};

LOGGER_EXPORT logger* create_logger();

} // namespace logging
