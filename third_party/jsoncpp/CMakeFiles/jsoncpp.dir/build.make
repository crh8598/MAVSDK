# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp

# Utility rule file for jsoncpp.

# Include the progress variables for this target.
include CMakeFiles/jsoncpp.dir/progress.make

CMakeFiles/jsoncpp: CMakeFiles/jsoncpp-complete


CMakeFiles/jsoncpp-complete: jsoncpp/src/jsoncpp-stamp/jsoncpp-install
CMakeFiles/jsoncpp-complete: jsoncpp/src/jsoncpp-stamp/jsoncpp-mkdir
CMakeFiles/jsoncpp-complete: jsoncpp/src/jsoncpp-stamp/jsoncpp-download
CMakeFiles/jsoncpp-complete: jsoncpp/src/jsoncpp-stamp/jsoncpp-update
CMakeFiles/jsoncpp-complete: jsoncpp/src/jsoncpp-stamp/jsoncpp-patch
CMakeFiles/jsoncpp-complete: jsoncpp/src/jsoncpp-stamp/jsoncpp-configure
CMakeFiles/jsoncpp-complete: jsoncpp/src/jsoncpp-stamp/jsoncpp-build
CMakeFiles/jsoncpp-complete: jsoncpp/src/jsoncpp-stamp/jsoncpp-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'jsoncpp'"
	/usr/bin/cmake -E make_directory /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles
	/usr/bin/cmake -E touch /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles/jsoncpp-complete
	/usr/bin/cmake -E touch /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp/jsoncpp-done

jsoncpp/src/jsoncpp-stamp/jsoncpp-install: jsoncpp/src/jsoncpp-stamp/jsoncpp-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Performing install step for 'jsoncpp'"
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-build && $(MAKE) install
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-build && /usr/bin/cmake -E touch /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp/jsoncpp-install

jsoncpp/src/jsoncpp-stamp/jsoncpp-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'jsoncpp'"
	/usr/bin/cmake -E make_directory /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp
	/usr/bin/cmake -E make_directory /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-build
	/usr/bin/cmake -E make_directory /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp
	/usr/bin/cmake -E make_directory /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/tmp
	/usr/bin/cmake -E make_directory /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp
	/usr/bin/cmake -E make_directory /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src
	/usr/bin/cmake -E make_directory /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp
	/usr/bin/cmake -E touch /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp/jsoncpp-mkdir

jsoncpp/src/jsoncpp-stamp/jsoncpp-download: jsoncpp/src/jsoncpp-stamp/jsoncpp-gitinfo.txt
jsoncpp/src/jsoncpp-stamp/jsoncpp-download: jsoncpp/src/jsoncpp-stamp/jsoncpp-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'jsoncpp'"
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src && /usr/bin/cmake -P /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/tmp/jsoncpp-gitclone.cmake
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src && /usr/bin/cmake -E touch /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp/jsoncpp-download

jsoncpp/src/jsoncpp-stamp/jsoncpp-update: jsoncpp/src/jsoncpp-stamp/jsoncpp-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'jsoncpp'"
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp && /usr/bin/cmake -P /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/tmp/jsoncpp-gitupdate.cmake

jsoncpp/src/jsoncpp-stamp/jsoncpp-patch: jsoncpp/src/jsoncpp-stamp/jsoncpp-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Performing patch step for 'jsoncpp'"
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp && git apply /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/fixlibname.patch
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp && /usr/bin/cmake -E touch /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp/jsoncpp-patch

jsoncpp/src/jsoncpp-stamp/jsoncpp-configure: jsoncpp/tmp/jsoncpp-cfgcmd.txt
jsoncpp/src/jsoncpp-stamp/jsoncpp-configure: jsoncpp/src/jsoncpp-stamp/jsoncpp-update
jsoncpp/src/jsoncpp-stamp/jsoncpp-configure: jsoncpp/src/jsoncpp-stamp/jsoncpp-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Performing configure step for 'jsoncpp'"
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-build && /usr/bin/cmake -DCMAKE_INSTALL_PREFIX:PATH=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/install -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DBUILD_SHARED_LIBS=OFF -DJSONCPP_WITH_CMAKE_PACKAGE=ON -DJSONCPP_WITH_TESTS=OFF "-GUnix Makefiles" /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-build && /usr/bin/cmake -E touch /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp/jsoncpp-configure

jsoncpp/src/jsoncpp-stamp/jsoncpp-build: jsoncpp/src/jsoncpp-stamp/jsoncpp-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Performing build step for 'jsoncpp'"
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-build && $(MAKE)
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-build && /usr/bin/cmake -E touch /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/jsoncpp/src/jsoncpp-stamp/jsoncpp-build

jsoncpp: CMakeFiles/jsoncpp
jsoncpp: CMakeFiles/jsoncpp-complete
jsoncpp: jsoncpp/src/jsoncpp-stamp/jsoncpp-install
jsoncpp: jsoncpp/src/jsoncpp-stamp/jsoncpp-mkdir
jsoncpp: jsoncpp/src/jsoncpp-stamp/jsoncpp-download
jsoncpp: jsoncpp/src/jsoncpp-stamp/jsoncpp-update
jsoncpp: jsoncpp/src/jsoncpp-stamp/jsoncpp-patch
jsoncpp: jsoncpp/src/jsoncpp-stamp/jsoncpp-configure
jsoncpp: jsoncpp/src/jsoncpp-stamp/jsoncpp-build
jsoncpp: CMakeFiles/jsoncpp.dir/build.make

.PHONY : jsoncpp

# Rule to build all files generated by this target.
CMakeFiles/jsoncpp.dir/build: jsoncpp

.PHONY : CMakeFiles/jsoncpp.dir/build

CMakeFiles/jsoncpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/jsoncpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/jsoncpp.dir/clean

CMakeFiles/jsoncpp.dir/depend:
	cd /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp /home/cho/Documents/pixhawk/mavsdk/MAVSDK/third_party/jsoncpp/CMakeFiles/jsoncpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/jsoncpp.dir/depend

