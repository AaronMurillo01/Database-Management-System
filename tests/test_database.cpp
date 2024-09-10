#include "database.h"
#include <gtest/gtest.h>

TEST(DatabaseTest, Create) {
    Database db;
    EXPECT_EQ(db.create("name", "John"), "Created: name = John");
}

TEST(DatabaseTest, Read) {
    Database db;
    db.create("name", "John");
    EXPECT_EQ(db.read("name"), "Read: name = John");
}

TEST(DatabaseTest, Update) {
    Database db;
    db.create("age", "30");
    EXPECT_EQ(db.update("age", "31"), "Updated: age = 31");
}

TEST(DatabaseTest, Delete) {
    Database db;
    db.create("age", "30");
    EXPECT_EQ(db.deleteKey("age"), "Deleted: age");
}

TEST(DatabaseTest, Query) {
    Database db;
    db.create("name", "John");
    db.create("age", "30");
    auto result = db.query("SELECT *");
    EXPECT_EQ(result.size(), 2);
    EXPECT_TRUE(result.find("name") != result.end());
    EXPECT_TRUE(result.find("age") != result.end());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}