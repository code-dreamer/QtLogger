#pragma once

#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <functional>
#include <QVariant>
#include <QDebug>
#include <QDateTime>
#pragma warning(pop)

#include "logger/logger_lib_switch.h"


namespace logging {

enum class log_level;

namespace impl {
struct stream_holder_data;
class logger_impl;
}; // namespace impl


struct LOGGER_EXPORT log_info
{
	log_info();

	logging::log_level log_level;
	const char* lib_id;
	const char* filename;
	int line;
	const char* function_name;
	QString captured_data;
	QDateTime time_stamp;
};


class LOGGER_EXPORT stream_holder
{
public:
	stream_holder(logging::impl::logger_impl* log_writer);
	stream_holder(stream_holder& other);
	stream_holder(const stream_holder&& other);
	stream_holder& operator=(stream_holder& other);
	~stream_holder();

public:
	QDebug& out() const;

public: // TODO: make private
	log_info& log_info();

private:
	impl::stream_holder_data* shared_data_;
};

} // namespace logging

// operator QDebug&() not overloarded for stream_holder. 
// In this case QDebug operator<<(QDebug, const QVariant &) will be called
