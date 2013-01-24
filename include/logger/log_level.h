#pragma once
/*
namespace logging
{

enum log_level
{
	debug_level = 0	// Debug messages. Can be useful for app debugging
					// "Point x pos changed to 104"

	, info_level		// Information messages. Can be useful for signaling about important events in application. 
					// This information can be interesting for administrators too.
					// "'Quake 2' game downloading started"

	, warning_level	// Can be useful if some strange, but non-fatal has happen
					// "Partial allocation for 'Quake 2' failed. Prepare for full allocation..."

	, error_level	// Error (not critical). Application may remain unstable but not crashing.
					// "Can't load icon 'smile.png'. Windows error 2."

	, critical_level	// Critical error. Some application components may not work correctly.
					// "Can't communicate with database. All data operations will be disabled"

	, fatal_level	// Fatal, unrecoverable error. Application in crash state and can't be recovered (unhandled exceptions handlers and etc).
					// "Unhanded Exception. Code 0xC0000005 (access violation). Adress:
};

}*/

namespace logging {
	/*
enum class log_level 
{
	debug_level = 0	// Debug messages. Can be useful for app debugging
					// "Point x pos changed to 104"

	, info_level	// Information messages. Can be useful for signaling about important events in application. 
					// This information can be interesting for administrators too.
					// "'Quake 2' game downloading started"

	, warning_level	// Can be useful if some strange, but non-fatal has happen
					// "Partial allocation for 'Quake 2' failed. Prepare for full allocation..."

	, error_level	// Error (not critical). Application may remain unstable but not crashing.
					// "Can't load icon 'smile.png'. Windows error 2."

	, critical_level	// Critical error. Some application components may not work correctly.
						// "Can't communicate with database. All data operations will be disabled"

	, fatal_level	// Fatal, unrecoverable error. Application in crash state and can't be recovered (unhandled exceptions handlers and etc).
					// "Unhanded Exception. Code 0xC0000005 (access violation). Adress:
};*/

enum class log_level
{
	  debug_level	=	0x0		// Debug messages. Can be useful for app debugging
								// "Point x pos changed to 104"

	, info_level	=	0x1		// Information messages. Can be useful for signaling about important events in application. 
								// This information can be interesting for administrators too.
								// "'Quake 2' game downloading started"

	, warning_level =	0x2		// Can be useful if some strange, but non-fatal has happen
								// "Partial allocation for 'Quake 2' failed. Prepare for full allocation..."

	, error_level	=	0x4		// Error (not critical). Application may remain unstable but not crashing.
								// "Can't load icon 'smile.png'. Windows error 2."

	, critical_level =	0x8		// Critical error. Some application components may not work correctly.
								// "Can't communicate with database. All data operations will be disabled"

	, fatal_level	=	0x10	// Fatal, unrecoverable error. Application in crash state and can't be recovered (unhandled exceptions handlers and etc).
								// "Unhanded Exception. Code 0xC0000005 (access violation). Address:

	, invalid_level	=	0x20
};
//Q_DECLARE_FLAGS(log_levels, log_level)

} // namespace logging

//Q_DECLARE_OPERATORS_FOR_FLAGS(logging::log_levels)