#include <iostream>
#include <filesystem>
#include <chrono>
#include <string>
#include <cassert>

#include "kvstore/storage.h"
#include "kvstore/log_manager.h"

namespace fs = std::filesystem;

int main(int argc, char **argv)
{
    // Hardcoded runfiles path
    fs::path logfile = fs::path(argv[0]).parent_path() / "data.log";

    std::ifstream f(logfile);
    if (!f.is_open())
    {
        std::cerr << "data.log not found at: " << logfile << std::endl;
        return 1;
    }

    Storage storage;
    LogManager log_manager(logfile.string());

    auto start = std::chrono::steady_clock::now();
    log_manager.load(storage);
    auto end = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "Restore took " << ms << " ms" << std::endl;

    int sz = storage.size();
    for (int i = 0; i < sz; i++)
    {
        std::string key = std::to_string(i);
        std::string expected = std::to_string(i);
        std::string got = storage.get(key);
        if (got != expected)
        {
            std::cerr << "Mismatch at " << i << ": got '" << got << "' expected '" << expected << "'\n";
            return 2;
        }
    }

    std::cout << "Validation passed" << std::endl;
    return 0;
}