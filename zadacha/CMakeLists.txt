cmake_minimum_required(VERSION 3.10)
project(zadacha)

set(CMAKE_CXX_STANDARD 17)

# Включаем поддержку тестов
enable_testing()

# Устанавливаем cpprestsdk
find_package(cpprestsdk REQUIRED)

# Подключаем GoogleTest с помощью FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Указываем файлы исходного кода
add_executable(main main.cpp)

# Указываем исполнимый файл для тестов
add_executable(UnitTests test.cpp)

# Связываем тесты с библиотеками cpprestsdk и GoogleTest
target_link_libraries(UnitTests
        cpprest
        GTest::GTest
        GTest::Main
)

# Настроим тесты
add_test(NAME UnitTests COMMAND UnitTests)
