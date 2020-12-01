cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(mission rotate_vehicle)

project(off_board)

if(NOT MSVC)
    add_definitions("-Wall -Wextra")
else()
    add_definitions("-WX -W2")
endif()

find_package(MAVSDK REQUIRED)

add_executable(off_board
    off_board.cpp
)

target_link_libraries(off_board
    MAVSDK::mavsdk_telemetry
    MAVSDK::mavsdk_action
    MAVSDK::mavsdk_mission
    MAVSDK::mavsdk_offboard
    MAVSDK::mavsdk
)
