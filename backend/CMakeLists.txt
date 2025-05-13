cmake_minimum_required(VERSION 3.12)
project(BattleZone)

set(CMAKE_CXX_STANDARD 17)

# Add our third_party folder to the include path
include_directories(${CMAKE_SOURCE_DIR}/third_party)
include_directories(${CMAKE_SOURCE_DIR}/third_party/asio/asio/include)
# find_package(Boost REQUIRED)
# include_directories(${Boost_INCLUDE_DIRS})
# target_link_libraries(server PRIVATE Boost::Boost)
add_executable(server
    src/main.cpp
    # src/auth.cpp
    # src/lobby.cpp
    # src/game_manager.cpp
)

# Link pthread (Crow needs this for multithreading)
target_link_libraries(server PRIVATE pthread)
