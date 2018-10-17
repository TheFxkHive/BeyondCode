#include "log.h"

#include <stdio.h>
#include <time.h>

const char* logger_arr [] = 
{
        "",
        "TRACE",
        "DEBUG",
        "INFO",
        "WARN",
        "ERROR",
        "FATAL"
};

void Logger(int* arr, size_t len, const int log_level, const char* val)
{
        printf("%s--%s:[", logger_arr[log_level],val);
        for (size_t i = 0; i < len; ++i) {
                printf("%d ", arr[i]);
        }
        printf("]\n");

}
void Logger(const char * str, const int log_level, const char* val)
{
        printf("%s--%s:[%s]\n", logger_arr[log_level], val, str);
}
