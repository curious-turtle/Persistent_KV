#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include "kvstore/log_manager.h"

namespace fs = std::filesystem;

void generate_test_data(const fs::path &logfile)
{
    fs::create_directories(logfile.parent_path());

    // Truncate or create the log file so LogManager starts fresh
    std::ofstream ofs(logfile.string(), std::ios::trunc);
    ofs.close();

    fs::path abspath = fs::absolute(logfile);
    std::cout << "Using log file: " << abspath << std::endl;

    LogManager log_manager(abspath.string());

    for (int i = 0; i < 100000; i++)
    {
        std::string key = std::to_string(i);
        std::string value = std::to_string(i);
        log_manager.log_put(key, value);
        if (i % 20000 == 0)
        {
            std::cout << "generated " << i << " entries\n";
        }
    }
}

int main(int argc, char **argv)
{
    fs::path logfile = "data/data.log";
    if (argc > 1)
    {
        logfile = argv[1];
    }

    generate_test_data(logfile);

    std::cout << "Test data generated!" << std::endl;
    return 0;
}
