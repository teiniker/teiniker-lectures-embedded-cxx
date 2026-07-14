#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <vector>

enum class LogLevel { FATAL, ERROR, WARNING, INFO, DEBUG };

class Logger
{
private:
    std::string _prefix;
    std::vector<std::string> _lines;

    static const char* to_string(LogLevel level);
    static std::string to_string(double value);

    void log(LogLevel level, const std::string& message);

public:
    // Constructor
    Logger(const std::string& prefix)
        : _prefix{prefix}
    {
    }

    // Accessors
    const std::vector<std::string>& lines() const { return _lines; }
    size_t size() const { return _lines.size(); }

    // Overloaded methods for each log level and each supported type
    // (const char* arguments bind to the std::string overloads)
    void fatal(const std::string& message) { log(LogLevel::FATAL, message); }
    void fatal(int value) { log(LogLevel::FATAL, std::to_string(value)); }
    void fatal(double value) { log(LogLevel::FATAL, to_string(value)); }
    void fatal(char value) { log(LogLevel::FATAL, std::string(1, value)); }

    void error(const std::string& message) { log(LogLevel::ERROR, message); }
    void error(int value) { log(LogLevel::ERROR, std::to_string(value)); }
    void error(double value) { log(LogLevel::ERROR, to_string(value)); }
    void error(char value) { log(LogLevel::ERROR, std::string(1, value)); }

    void warning(const std::string& message) { log(LogLevel::WARNING, message); }
    void warning(int value) { log(LogLevel::WARNING, std::to_string(value)); }
    void warning(double value) { log(LogLevel::WARNING, to_string(value)); }
    void warning(char value) { log(LogLevel::WARNING, std::string(1, value)); }

    void info(const std::string& message) { log(LogLevel::INFO, message); }
    void info(int value) { log(LogLevel::INFO, std::to_string(value)); }
    void info(double value) { log(LogLevel::INFO, to_string(value)); }
    void info(char value) { log(LogLevel::INFO, std::string(1, value)); }

    void debug(const std::string& message) { log(LogLevel::DEBUG, message); }
    void debug(int value) { log(LogLevel::DEBUG, std::to_string(value)); }
    void debug(double value) { log(LogLevel::DEBUG, to_string(value)); }
    void debug(char value) { log(LogLevel::DEBUG, std::string(1, value)); }
};

#endif
