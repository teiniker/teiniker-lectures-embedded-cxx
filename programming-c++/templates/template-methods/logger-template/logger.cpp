#include "logger.h"

const char* Logger::to_string(LogLevel level)
{
    switch (level)
    {
        case LogLevel::FATAL:   return "FATAL";
        case LogLevel::ERROR:   return "ERROR";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::INFO:    return "INFO";
        case LogLevel::DEBUG:   return "DEBUG";
    }
    return "UNKNOWN";
}
