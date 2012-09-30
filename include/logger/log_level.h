#pragma once

namespace Logging
{

enum LogLevel
{
	DebugLevel = 0	// Debug messages. Can be useful for app debugging
					// "Point x pos changed to 104"

	, InfoLevel		// Information messages. Can be useful for signaling about important events in application. 
					// This information can be interesting for administrators too.
					// "'Quake 2' game downloading started"

	, WarningLevel	// Can be useful if some strange, but non-fatal has happen
					// "Partial allocation for 'Quake 2' failed. Prepare for full allocation..."

	, ErrorLevel	// Error (not critical). Application may remain unstable but not crashing.
					// "Can't load icon 'smile.png'. Windows error 2."

	, CriticalLevel	// Critical error. Some application components may not work correctly.
					// "Can't communicate with database. All data operations will be disabled"

	, FatalLevel	// Fatal, unrecoverable error. Application in crash state and can't be recovered (unhandled exceptions handlers and etc).
					// "Unhanded Exception. Code 0xC0000005 (access violation). Adress:
};

}