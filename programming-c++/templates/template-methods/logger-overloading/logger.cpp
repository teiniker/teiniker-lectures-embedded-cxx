#include <sstream>

#include "logger.h"

// Without template methods, the whole implementation can live in the
// source file - only trivial one-liners stay inline in the header.

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

// std::to_string(36.6) would produce "36.600000", so we format
// double values using a string stream.
std::string Logger::to_string(double value)
{
    std::ostringstream stream;
    stream << value;
    return stream.str();
}

void Logger::log(LogLevel level, const std::string& message)
{
    std::ostringstream line;
    line << _prefix << " " << to_string(level) << ": " << message;
    _lines.push_back(line.str());
}
