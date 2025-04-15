cmake_minimum_required(VERSION 3.15)
project(BattleZone VERSION 0.1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Boost REQUIRED COMPONENTS system)
find_package(Threads REQUIRED)

# Add subdirectories
add_subdirectory(src)

# Set include directories
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)

# Add executables
add_executable(server src/server/main.cpp)
add_executable(client src/client/main.cpp)
add_executable(tic_tac_toe src/tic_tac_toe_main.cpp src/common/games/tic_tac_toe/tic_tac_toe.cpp)

# Link libraries
target_link_libraries(server
    PRIVATE
    Boost::system
    Threads::Threads
)

target_link_libraries(client
    PRIVATE
    Boost::system
    Threads::Threads
) 