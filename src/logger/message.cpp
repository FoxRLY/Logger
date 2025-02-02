#include <logger/message.h>

namespace logger {

const char* format_as(LogLevel level) {
    switch (level) {
        case LogLevel::ALL: return "ALL";
        case LogLevel::TRACE: return "TRACE";
        case LogLevel::DEBUG: return "DEBUG";
        case LogLevel::INFO: return "INFO";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::FATAL: return "FATAL";
        default: return "UNDEFINED";
    }
}

}

