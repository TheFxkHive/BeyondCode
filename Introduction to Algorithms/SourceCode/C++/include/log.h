#include <stddef.h>
#ifndef __LOG__H_
#define __LOG__H_

#define LOG_TRACE_LEVEL 1
#define LOG_DEBUG_LEVEL 2
#define LOG_INFO_LEVEL 3
#define LOG_WARN_LEVEL 4
#define LOG_ERROR_LEVEL 5
#define LOG_FATAL_LEVEL 6

void Logger(int* arr, size_t len, const int log_level = LOG_DEBUG_LEVEL, const char* val = "");

void Logger(const char* str, const int log_level = LOG_DEBUG_LEVEL, const char* val = "");

#endif

