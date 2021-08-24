#include <iostream>
#include <vector>

//必须定义这个宏,才能输出文件名和行号，需要在include之前定义
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"

constexpr char MODULE_NAME[] = "spdlog_demo";
constexpr char MODULE2_NAME[] = "spdlog2_demo";
constexpr char LOG_FILE_NAME[] = "logs/daily.txt";

std::shared_ptr<spdlog::logger> LogDailyFileConfig(void)
{
    try
    {
        // Create a daily logger - a new file is created every day on 2:30am.
        auto logger = spdlog::daily_logger_mt(MODULE_NAME, LOG_FILE_NAME, 2, 30);
        logger->set_pattern("[%H:%M:%S %z] [%n] [%l] [thread %t] %v");
        return logger;
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        spdlog::error("Log init failed: ", ex.what());
        return std::shared_ptr<spdlog::logger>(nullptr);
    }
}

int main()
{
    std::vector<int> a;
    a.push_back(1);
    spdlog::info("a {}", a[0]);

    // auto logger = LogDailyFileConfig();
    auto logger = spdlog::daily_logger_mt(MODULE_NAME, LOG_FILE_NAME, 2, 30);
    logger->set_pattern("[%H:%M:%S %z] [%n] [%l] [thread %t] %v");
    logger->info("Welcome to spdlog!");
    logger->error("Some error message with arg: {}", 1);
    logger->warn("Easy padding in numbers like {:08d}", 12);
    logger->critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);

    //获取log指针
    logger = spdlog::get(MODULE_NAME);
    logger->info("Support for floats {:03.2f}", 1.23456);

    //这里有个疑问，为什么后面的log先打印
    auto logger1 = spdlog::daily_logger_mt(MODULE2_NAME, LOG_FILE_NAME, 2, 30);
    logger1->set_pattern("[%H:%M:%S %z] [%n] [%l] [thread %t] %v");
    logger1->info("Positional args are {1} {0}..", "too", "supported");
    logger1->info("{:<30}", "left aligned");

    logger1->set_level(spdlog::level::debug); // Set global log level to debug
    logger1->debug("This message should be displayed..");

    // change log pattern
    logger1->set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %!:%# %v");
    SPDLOG_LOGGER_INFO(logger1, "Some trace message with param {}", 42);
    SPDLOG_LOGGER_DEBUG(logger1, "Some debug message");
}