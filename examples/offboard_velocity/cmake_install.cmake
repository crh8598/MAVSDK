# Install script for directory: /home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/battery/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/calibrate/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/fly_mission/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/fly_multiple_drones/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/fly_qgc_mission/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/follow_me/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/geofence_inclusion/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/gimbal_device_tester/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/mavshell/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/manual_control/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/multiple_drones/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/offboard_velocity/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/takeoff_land/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/transition_vtol_fixed_wing/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/tune/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/ftp_client/cmake_install.cmake")
  include("/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/ftp_server/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/cho/Documents/pixhawk/mavsdk/MAVSDK/examples/offboard_velocity/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
