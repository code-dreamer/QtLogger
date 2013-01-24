#pragma once

#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QObject>
#include <QDebug>
#pragma warning(pop)

#include "logger/impl/logger_lib_switch.h"
#include "logger/stream_holder.h"
#include "logger/capture_type.h"

namespace logging {
enum class log_level;
enum class capture_type;
namespace impl {
class log_writer;
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

	stream_holder make_stream(log_level log_level, const char* file, int line, const char* function_name, const char* lib_id = nullptr);
	//QDebug stream(qint64 lib_id, const char* file, int line, const char* function);
	//QDebug stream(const char* lib_id_str, const char* file, int line, const char* function);

private:
	void write(const log_info& log_info, const QString& message);
	
#pragma warning(push)
#pragma warning(disable : 4251)
private:
	QScopedPointer<impl::log_writer> log_writer_;
#pragma warning(pop)
};

LOGGER_EXPORT logger* create_logger();

} // logging
