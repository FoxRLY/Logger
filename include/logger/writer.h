#pragma once
#include <logger/message.h>

namespace logger {

class LogWriter {
protected:
    LogLevel current_level;
public:
    LogWriter(LogLevel level): current_level(level) {}
    virtual void write_log(const char* message_string, const LogMessage& message) const = 0;
};

}
