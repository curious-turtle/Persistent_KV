#include "log_manager.h"
#include "storage.h"
#include <iostream>

LogManager::LogManager(const std::string &log_file) : log_file_(log_file)
{
    log_stream_.open(log_file_, std::ios::app);
}

LogManager::~LogManager()
{
    if (log_stream_.is_open())
    {
        log_stream_.close();
    }
}

void LogManager::log_put(const std::string &key, const std::string &value)
{
    if (log_stream_.is_open())
    {
        log_stream_ << key << " " << value << std::endl;
    }
}

void LogManager::load(Storage &storage)
{
    std::ifstream replay_stream(log_file_);
    std::string key, value;

    // Each log line is expected to be: <key> <value>
    // Read both tokens in the loop to avoid shifting tokens (was reading an extra
    // "operation" token per iteration which desynced subsequent reads).
    while (replay_stream >> key >> value)
    {
        storage.put(key, value);
    }
}
