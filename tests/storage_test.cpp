#include "../kvstore/storage.h"
#include <cassert>
#include <iostream>

void test_put_and_get()
{
    Storage storage;
    storage.put("test_key", "test_value");
    assert(storage.get("test_key") == "test_value");
    std::cout << "test_put_and_get passed" << std::endl;
}

void test_remove()
{
    Storage storage;
    storage.put("key", "value");
    assert(storage.remove("key") == true);
    assert(storage.get("key") == "");
    std::cout << "test_remove passed" << std::endl;
}

void test_exists()
{
    Storage storage;
    storage.put("key", "value");
    assert(storage.exists("key") == true);
    assert(storage.exists("nonexistent") == false);
    std::cout << "test_exists passed" << std::endl;
}

int main()
{
    test_put_and_get();
    test_remove();
    test_exists();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
