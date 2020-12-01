#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "JsonCpp::jsoncpp" for configuration "Release"
set_property(TARGET JsonCpp::jsoncpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(JsonCpp::jsoncpp PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libjsoncpp.a"
  )

list(APPEND _IMPORT_CHECK_TARGETS JsonCpp::jsoncpp )
list(APPEND _IMPORT_CHECK_FILES_FOR_JsonCpp::jsoncpp "${_IMPORT_PREFIX}/lib/libjsoncpp.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
