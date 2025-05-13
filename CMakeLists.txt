cmake_minimum_required(VERSION 3.15)
project(BattleZone VERSION 0.1.0 LANGUAGES CXX)

# Add vcpkg toolchain
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Threads REQUIRED)

# Set include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/common
    ${CMAKE_SOURCE_DIR}/src/common/games
    ${CMAKE_SOURCE_DIR}/src/common/types
)

# Add executables
add_executable(tic_tac_toe 
    src/tic_tac_toe_main.cpp 
    src/common/games/tic_tac_toe/tic_tac_toe.cpp
    src/common/games/game.hpp
    src/common/types/game_types.hpp
)

# Link libraries
target_link_libraries(tic_tac_toe
    PRIVATE
    Threads::Threads
)
