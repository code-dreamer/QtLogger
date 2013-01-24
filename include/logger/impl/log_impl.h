#pragma once

#pragma warning(push, 0)
#include <QScopedPointer>
#include <QMutex>
#pragma warning(pop)

#include "logger/stream_holder.h"

namespace logging {

enum class capture_type;

namespace impl {

class log_impl
{
	Q_DISABLE_COPY(log_impl);

public:
	log_impl();
	~log_impl();

public:
	void set_capture_data(capture_type capture_type);

	logging::stream_holder make_stream(log_level log_level, const char* file, int line, const char* function_name, const char* lib_id = nullptr);
	
	void write(const logging::log_info& log_info, const QString& message);
	//void write(log_level log_level, const char* file, int line, const char* function_name, const QString& message);

private:
	capture_type capture_type_;
};

} // namespace impl
} // namespace logging