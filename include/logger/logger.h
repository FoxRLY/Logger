#pragma once

#include <source_location>
#include <string>

namespace logger {

class Logger {
public:
    virtual void trace(const std::string& message, const std::source_location& location) const noexcept = 0;
    virtual void debug(const std::string& message, const std::source_location& location) const noexcept = 0;
    virtual void info(const std::string& message, const std::source_location& location) const noexcept = 0;
    virtual void warning(const std::string& message, const std::source_location& location) const noexcept = 0;
    virtual void error(const std::string& message, const std::source_location& location) const noexcept = 0;
    virtual void fatal(const std::string& message, const std::source_location& location) const noexcept = 0;
};

}

