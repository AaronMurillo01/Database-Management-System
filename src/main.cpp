#include "database.h"
#include <iostream>

int main() {
    Database db;
    std::cout << db.create("name", "John") << std::endl;
    std::cout << db.create("age", "30") << std::endl;
    std::cout << db.read("name") << std::endl;
    std::cout << db.update("age", "31") << std::endl;
    std::cout << db.read("age") << std::endl;
    std::cout << db.deleteKey("age") << std::endl;
    std::cout << db.read("age") << std::endl;
    auto result = db.query("SELECT *");
    for (const auto& pair : result) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
    return 0;
}