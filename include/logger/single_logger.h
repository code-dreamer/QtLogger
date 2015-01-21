#pragma once

#include "logger/logger.h"

namespace logging {
LOGGER_EXPORT logger* single_logger();
LOGGER_EXPORT void shutdown_logger(); // manually shutdown logger
} // namespace logging


#define LOG_DEBUG()		\
	logging::single_logger()->stream_helper(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO).stream()

#define LIB_LOG_DEBUG(lib_id_str)	\
	logging::single_logger()->stream_helper(logging::log_level::debug_level, __FILE__, __LINE__, Q_FUNC_INFO, lib_id_str).stream()


#define LOG_INFO()		\
	logging::single_logger()->stream_helper(logging::log_level::info_level, __FILE__, __LINE__, Q_FUNC_INFO).stream()

#define LIB_LOG_INFO(lib_id_str)	\
	logging::single_logger()->stream_helper(logging::log_level::info_level, __FILE__, __LINE__, Q_FUNC_INFO, lib_id_str).stream()


#define LOG_WARNING()	\
	logging::single_logger()->stream_helper(logging::log_level::warning_level, __FILE__, __LINE__, Q_FUNC_INFO).stream()

#define LIB_LOG_WARNING(lib_id_str)	\
	logging::single_logger()->stream_helper(logging::log_level::warning_level, __FILE__, __LINE__, Q_FUNC_INFO, lib_id_str).stream()


#define LOG_ERROR()		\
	logging::single_logger()->stream_helper(logging::log_level::error_level, __FILE__, __LINE__, Q_FUNC_INFO).stream()

#define LIB_LOG_ERROR(lib_id_str)	\
	logging::single_logger()->stream_helper(logging::log_level::error_level, __FILE__, __LINE__, Q_FUNC_INFO, lib_id_str).stream()


#define LOG_CRITICAL()		\
	logging::single_logger()->stream_helper(logging::log_level::critical_level, __FILE__, __LINE__, Q_FUNC_INFO).stream()

#define LIB_LOG_CRITICAL(lib_id_str)	\
	logging::single_logger()->stream_helper(logging::log_level::critical_level, __FILE__, __LINE__, Q_FUNC_INFO, lib_id_str).stream()


#define LOG_FATAL()		\
	logging::single_logger()->stream_helper(logging::log_level::fatal_level, __FILE__, __LINE__, Q_FUNC_INFO).stream()

#define LIB_LOG_FATAL(lib_id_str)	\
	logging::single_logger()->stream_helper(logging::log_level::fatal_level, __FILE__, __LINE__, Q_FUNC_INFO, lib_id_str).stream()
