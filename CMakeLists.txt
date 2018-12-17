cmake_minimum_required(VERSION 3.5)

project(testBlowFish VERSION 0.0.1 LANGUAGES CXX)

add_executable(testBlowFish
    main.cpp

    blowfish.h
    blowfish.h2
    blowfish.cpp)

target_include_directories(testBlowFish
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)