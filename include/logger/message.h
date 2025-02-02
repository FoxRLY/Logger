#pragma once
#include <chrono>
#include <source_location>

namespace logger {

enum LogLevel {ALL, TRACE, DEBUG, INFO, WARNING, ERROR, FATAL};

const char* format_as(LogLevel level);

using TimePoint = std::chrono::time_point<std::chrono::system_clock>;

class LogMessage {
private:
    LogLevel level;
    TimePoint time_point;
    std::source_location location;
    std::string message;
public:
    LogMessage(LogLevel level, std::source_location location, std::string message):
        level(level),
        time_point(std::chrono::system_clock::now()),
        location(location),
        message(message) {}
    const std::string& get_log_message() const noexcept {
        return message;
    }
    LogLevel get_log_level() const noexcept {
        return level;
    }
    const TimePoint& get_time_point() const noexcept {
        return time_point;
    }
    const std::source_location& get_source_location() const noexcept {
        return location;
    }
};

}
