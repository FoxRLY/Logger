#pragma once
#include <logger/message.h>
#include <logger/writer.h>
#include <logger/logger.h>

namespace logger {

class SimpleLogWriter: public LogWriter {
public:
    SimpleLogWriter(LogLevel current_level): LogWriter(current_level) {}
    void write_log(const char* message_string, const LogMessage& message) const override;
};

class SimpleLogger: public Logger {
private:
    SimpleLogWriter log_writer;

    void write_log(const std::string& message,
                   const std::source_location &location,
                   LogLevel level) const noexcept;
public:
    SimpleLogger(LogLevel level):
        log_writer(level) {}

    void trace(const std::string &message,
               const std::source_location &location = std::source_location::current()) const noexcept override {
        write_log(message, location, LogLevel::TRACE);
    }

    void debug(const std::string &message,
               const std::source_location &location = std::source_location::current()) const noexcept override {
        write_log(message, location, LogLevel::DEBUG);
    }

    void info(const std::string &message,
              const std::source_location &location = std::source_location::current()) const noexcept override {
        write_log(message, location, LogLevel::INFO);
    }

    void warning(const std::string &message,
                 const std::source_location &location = std::source_location::current()) const noexcept override {
        write_log(message, location, LogLevel::WARNING);
    }

    void error(const std::string &message,
               const std::source_location &location = std::source_location::current()) const noexcept override {
        write_log(message, location, LogLevel::ERROR);
    }

    void fatal(const std::string &message,
               const std::source_location &location = std::source_location::current()) const noexcept override {
        write_log(message, location, LogLevel::FATAL);
    }
};

}
