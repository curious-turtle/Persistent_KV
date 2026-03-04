#include "storage.h"

Storage::Storage() {}

Storage::~Storage() {}

void Storage::put(const std::string &key, const std::string &value)
{
    data_[key] = value;
}

std::string Storage::get(const std::string &key)
{
    auto it = data_.find(key);
    if (it != data_.end())
    {
        return it->second;
    }
    return "";
}

bool Storage::remove(const std::string &key)
{
    return data_.erase(key) > 0;
}

bool Storage::exists(const std::string &key)
{
    return data_.find(key) != data_.end();
}

int Storage::size() const
{
    return data_.size();
}
