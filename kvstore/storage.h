#ifndef KVSTORE_STORAGE_H
#define KVSTORE_STORAGE_H

#include <string>
#include <unordered_map>

class Storage
{
public:
    Storage();
    ~Storage();

    void put(const std::string &key, const std::string &value);
    std::string get(const std::string &key);
    bool remove(const std::string &key);
    bool exists(const std::string &key);

private:
    std::unordered_map<std::string, std::string> data_;
};

#endif // KVSTORE_STORAGE_H
