#ifndef DATABASE_H
#define DATABASE_H

#include <unordered_map>
#include <string>

class Database {
public:
    Database();
    std::string create(const std::string& key, const std::string& value);
    std::string read(const std::string& key);
    std::string update(const std::string& key, const std::string& value);
    std::string deleteKey(const std::string& key);
    std::unordered_map<std::string, std::string> query(const std::string& condition);

private:
    std::unordered_map<std::string, std::string> data;
};

#endif // DATABASE_H