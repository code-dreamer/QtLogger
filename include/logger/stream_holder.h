#pragma once

#include <functional>
#include "logger/impl/logger_lib_switch.h"

namespace logging
{
namespace impl
{
class stream_holder_data;
}

typedef std::function<void()> delete_handler;

class LOGGER_EXPORT stream_holder
{
public:
	stream_holder(const QDebug& stream, delete_handler delete_handler);
	stream_holder(const stream_holder& other);
	~stream_holder();

public:
	operator QDebug&();

private:
	stream_holder& stream_holder::operator=(const stream_holder&);

private:
	impl::stream_holder_data* data_;

#pragma warning(push)
#pragma warning(disable : 4251)
private:
	delete_handler delete_handler_;
#pragma warning(pop)
};
} // logging namespace