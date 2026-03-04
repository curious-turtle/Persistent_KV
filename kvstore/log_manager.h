#ifndef KVSTORE_LOG_MANAGER_H
#define KVSTORE_LOG_MANAGER_H

#include <string>
#include <fstream>

class Storage;

class LogManager
{
public:
    LogManager(const std::string &log_file, Storage &storage);
    ~LogManager();

    void log_put(const std::string &key, const std::string &value, bool log_to_storage = true);
    void load(Storage &storage);

private:
    std::string log_file_;
    std::ofstream log_stream_;
    Storage &storage_;
};

#endif // KVSTORE_LOG_MANAGER_H
