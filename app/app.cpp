#include <logger/simple.h>
#include <fmt/format.h>
#include <thread>

int main() {
    auto log = logger::SimpleLogger(logger::LogLevel::INFO);

    auto printer = [&](int number) {
        for (int i = 0; i < 100; i++) {
            log.info(fmt::format("Hello {}: {}", number, i));
        }
    };

    auto thread_one = std::thread(printer, 1);
    auto thread_two = std::thread(printer, 2);
    auto thread_three = std::thread(printer, 3);
    auto thread_four = std::thread(printer, 4);
    auto thread_five = std::thread(printer, 5);

    thread_one.join();
    thread_two.join();
    thread_three.join();
    thread_four.join();
    thread_five.join();

    log.info("END");

}
