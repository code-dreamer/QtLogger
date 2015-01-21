#pragma once

namespace logging {
;
enum class capture_type : int
{
	no_capture = 0x0,
	proc_id = 0x1,
	thread_id = 0x2,
	invalid = 0x4
};
} // namespace logging
