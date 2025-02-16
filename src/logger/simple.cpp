#include <logger/simple.h>
#include <fmt/core.h>
#include <fmt/chrono.h>

namespace logger {

void SimpleLogWriter::write_log(const char* message_string, const LogMessage& message) const {
    if (message.get_log_level() >= current_level) {
        fmt::println("{}", message_string);
    }
}

void SimpleLogger::write_log(const std::string& message,
               const std::source_location &location,
               LogLevel level) const noexcept {

    const LogMessage message_metadata = LogMessage(level, location, message);
    const std::string formatted_message = fmt::format("{:%Y-%m-%d %H:%M:%S} {} [{}:{}:{}] - {}",
                 std::chrono::floor<std::chrono::milliseconds>(message_metadata.get_time_point()),
                 format_as(message_metadata.get_log_level()),
                 message_metadata.get_source_location().file_name(),
                 message_metadata.get_source_location().function_name(),
                 message_metadata.get_source_location().line(),
                 message_metadata.get_log_message());
    log_writer.write_log(formatted_message.c_str(), message_metadata);
}

}

