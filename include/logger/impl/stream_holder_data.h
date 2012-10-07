#pragma once

#pragma warning(push, 0)
#include <QSharedData>
#include <QDebug>
#pragma warning(pop)

#include "logger/log_level.h"

namespace logging
{
enum log_level;

namespace impl
{

class log_writer;

class stream_holder_data : public QSharedData
{
	Q_DISABLE_COPY(stream_holder_data)

public:
	stream_holder_data();
	~stream_holder_data();

public:
	QDebug& stream();

public:
	void set_writer(logging::impl::log_writer* log_writer);
	void set_log_level(logging::log_level log_level);
	void set_filename(const char* filename);
	void set_line(int line);
	void set_function_name(const char* function_name);

private:
	QDebug stream_;
	QString buffer_;

	log_writer* log_writer_;
	logging::log_level log_Level_;
	const char* filename_;
	int line_;
	const char* function_name_;
};

} // impl
} // logging