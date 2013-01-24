#pragma warning(push, 0)
#pragma warning(disable: 4350)
#include <QString>

#define NOMINMAX
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#ifndef _INC_WINDOWS
	#include <Windows.h>
#endif
#pragma warning(pop)

#include "logger/debug_writer.h"


namespace logging {

debug_writer::debug_writer()
{
}

debug_writer::~debug_writer()
{
}

void debug_writer::do_write(const QString& log_entry)
{
	OutputDebugString((LPCWSTR) log_entry.utf16());
}

} // namespace logging