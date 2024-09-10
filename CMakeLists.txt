cmake_minimum_required(VERSION 3.10)
project(LightweightDatabaseSystem)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main src/main.cpp src/database.cpp)
add_executable(test_database tests/test_database.cpp src/database.cpp)

include(GoogleTest)
add_executable(${PROJECT_NAME}-test tests/test_database.cpp)
target_link_libraries(${PROJECT_NAME}-test GTest::GTest)