#include <logger/simple.h>
#include <fmt/format.h>

int main() {
    auto log = logger::SimpleLogger(logger::LogLevel::INFO);
    for (int i = 0; i < 100; i++) {
        log.info(fmt::format("Hello: {}", i));
    }
}
