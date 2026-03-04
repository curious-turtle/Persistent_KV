#include "log_manager.h"
#include "storage.h"
#include <iostream>

LogManager::LogManager(const std::string &log_file, Storage &storage) : log_file_(log_file), storage_(storage)
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

void LogManager::log_put(const std::string &key, const std::string &value, bool log_to_storage)
{
    if (log_stream_.is_open())
    {
        log_stream_ << "P " << key << " " << value << std::endl;
    }
    if (log_to_storage)
    {
        storage_.put(key, value);
    }
}

void LogManager::load(Storage &storage)
{
    std::ifstream replay_stream(log_file_);
    std::string operation, key, value;

    while (replay_stream >> operation)
    {
        if (operation == "P")
        {
            replay_stream >> key >> value;
            storage.put(key, value);
        }
    }
}
