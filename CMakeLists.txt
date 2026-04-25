cmake_minimum_required(VERSION 3.10)
project(CardMaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(code main.cpp)

# Set optimization flags
set_target_properties(code PROPERTIES
    CXX_FLAGS "-O2 -Wall -Wextra"
)
