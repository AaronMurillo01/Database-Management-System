#include "database.h"

Database::Database() : data() {}

std::string Database::create(const std::string& key, const std::string& value) {
    data[key] = value;
    return "Created: " + key + " = " + value;
}

std::string Database::read(const std::string& key) {
    if (data.find(key) != data.end()) {
        return "Read: " + key + " = " + data[key];
    } else {
        return "Key '" + key + "' not found.";
    }
}

std::string Database::update(const std::string& key, const std::string& value) {
    if (data.find(key) != data.end()) {
        data[key] = value;
        return "Updated: " + key + " = " + value;
    } else {
        return "Key '" + key + "' not found.";
    }
}

std::string Database::deleteKey(const std::string& key) {
    if (data.find(key) != data.end()) {
        data.erase(key);
        return "Deleted: " + key;
    } else {
        return "Key '" + key + "' not found.";
    }
}

std::unordered_map<std::string, std::string> Database::query(const std::string& condition) {
    // Simple query support for demonstration purposes
    if (condition.find("SELECT") != std::string::npos) {
        return data;
    } else {
        return {};
    }
}