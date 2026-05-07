cmake_minimum_required(VERSION 3.16)
project(OOP_Pazymiu_Sistema VERSION 1.5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

add_library(pazymiu_sistema_lib
    vector/funkcijos.cpp
)

target_include_directories(pazymiu_sistema_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/vector
)

add_executable(programa
    vector/main.cpp
    vector/tests.cpp
)

target_link_libraries(programa PRIVATE
    pazymiu_sistema_lib
)

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.14.0
)

FetchContent_MakeAvailable(Catch2)

list(APPEND CMAKE_MODULE_PATH
    ${catch2_SOURCE_DIR}/extras
)

add_executable(unit_tests
    tests/unit_tests.cpp
)

target_link_libraries(unit_tests PRIVATE
    pazymiu_sistema_lib
    Catch2::Catch2WithMain
)

include(CTest)
include(Catch)

catch_discover_tests(unit_tests)
