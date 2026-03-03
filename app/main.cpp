#include <iostream>
#include "../kvstore/storage.h"
#include "../kvstore/log_manager.h"

int main()
{
    Storage storage;
    LogManager log_manager("data/data.log");

    // Replay log on startup
    log_manager.replay(storage);

    std::cout << "Persistent Key-Value Store initialized" << std::endl;

    // Example usage
    storage.put("key1", "value1");
    log_manager.log_put("key1", "value1");

    std::cout << "key1: " << storage.get("key1") << std::endl;

    return 0;
}
