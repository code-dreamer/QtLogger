#pragma once

#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <functional>
#include <QVariant>
#include <QDebug>
#pragma warning(pop)

#include "logger/impl/logger_lib_switch.h"

namespace logging {

enum class log_level;

namespace impl {
struct stream_holder_data;
class log_writer;
}; // namespace impl

struct LOGGER_EXPORT log_info
{
	log_info();

	logging::log_level log_level;
	const char* module_id;
	const char* filename;
	int line;
	const char* function_name;
};

class LOGGER_EXPORT stream_holder
{
public:
	stream_holder(logging::impl::log_writer* log_writer);
	stream_holder(stream_holder& other);
	stream_holder(const stream_holder&& other);
	stream_holder& operator=(stream_holder& other);
	~stream_holder();

public:
	QDebug& out() const;

public: // TODO: make private
	log_info& log_info();
	/*
public:
	void set_log_level(logging::log_level log_level);
	void set_filename(const char* filename);
	void set_line(int line);
	void set_function_name(const char* function_name);
	*/
//private:
	//stream_holder& stream_holder::operator=(const stream_holder&);

private:
	impl::stream_holder_data* shared_data_;
};

} // namespace logging

// operator QDebug&() not overloarded for stream_holder. 
// In this case QDebug operator<<(QDebug, const QVariant &) will be called
