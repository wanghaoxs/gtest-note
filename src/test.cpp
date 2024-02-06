#include "common.h"

TEST(gtest, test2) {
    std::string filename = "/etc/rtsp/stream_config_1.json";
    int64_t time = Util::get_update_time(filename);
    std::cout << "time = " << time << std::endl;
}

TEST(gtest, test3) {
    struct sysinfo memInfo {};
    if (sysinfo(&memInfo) == -1) {
        std::cerr << "Failed to get memory info." << std::endl;
    }
    unsigned long totalMemory = memInfo.totalram / 1024 / 1024 / 1024;
    unsigned long freeMemory = memInfo.freeram / 1024 / 1024 / 1024;
    unsigned long usedMemory = totalMemory - freeMemory;

    double usagePercentage = (static_cast<double>(usedMemory) / static_cast<double>(totalMemory)) * 100.0;
    double memoryUsage = usagePercentage;
    std::cout << "Memory Usage: " << memoryUsage << "%" << std::endl;
}
