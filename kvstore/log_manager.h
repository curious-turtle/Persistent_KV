#ifndef KVSTORE_LOG_MANAGER_H
#define KVSTORE_LOG_MANAGER_H

#include <string>
#include <fstream>

class LogManager
{
public:
    LogManager(const std::string &log_file);
    ~LogManager();

    void log_put(const std::string &key, const std::string &value);
    void load(class Storage &storage);

private:
    std::string log_file_;
    std::ofstream log_stream_;
};

#endif // KVSTORE_LOG_MANAGER_H
