#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <sstream>
#include <vector>

enum class LogLevel { FATAL, ERROR, WARNING, INFO, DEBUG };

class Logger
{
private:
    std::string _prefix;
    std::vector<std::string> _lines;

    static const char* to_string(LogLevel level);

    template <typename T>
    void log(LogLevel level, const T& message)
    {
        std::ostringstream line;
        line << _prefix << " " << to_string(level) << ": " << message;
        _lines.push_back(line.str());
    }

public:
    // Constructor
    Logger(const std::string& prefix)
        : _prefix{prefix}
    {
    }

    // Accessors
    const std::vector<std::string>& lines() const { return _lines; }
    size_t size() const { return _lines.size(); }

    // Template methods - one for each log level
    template <typename T>
    void fatal(const T& message) { log(LogLevel::FATAL, message); }

    template <typename T>
    void error(const T& message) { log(LogLevel::ERROR, message); }

    template <typename T>
    void warning(const T& message) { log(LogLevel::WARNING, message); }

    template <typename T>
    void info(const T& message) { log(LogLevel::INFO, message); }

    template <typename T>
    void debug(const T& message) { log(LogLevel::DEBUG, message); }
};

#endif
