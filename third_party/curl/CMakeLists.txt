cmake_minimum_required(VERSION 3.1)

project(external-curl)
include(ExternalProject)

list(APPEND CMAKE_ARGS
    "${CL_ARGS}"
    "-DCMAKE_INSTALL_PREFIX:PATH=${CMAKE_INSTALL_PREFIX}"
    "-DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}"
    "-DCMAKE_POSITION_INDEPENDENT_CODE=ON"
    "-DCMAKE_USE_OPENSSL=OFF"
    "-DCMAKE_USE_LIBSSH2=OFF"
    "-DBUILD_SHARED_LIBS=OFF"
    "-DCURL_CA_PATH_SET=OFF"
    "-DCURL_ZLIB=OFF"
    "-DHTTP_ONLY=ON"
    "-DHAVE_POSIX_STRERROR_R=1"
    "-DBUILD_TESTING=OFF"
    )

if(ANDROID)
    list(APPEND CMAKE_ARGS
        "-DBUILD_CURL_EXE=OFF"
        )
elseif(IOS)
    list(APPEND CMAKE_ARGS
        "-DBUILD_CURL_EXE=OFF"
        )
endif()

message(STATUS "Preparing external project \"curl\" with args:")
foreach(CMAKE_ARG ${CMAKE_ARGS})
    message(STATUS "-- ${CMAKE_ARG}")
endforeach()

ExternalProject_add(
    curl
    GIT_REPOSITORY https://github.com/curl/curl.git
    GIT_TAG curl-7_73_0
    GIT_SHALLOW ON
    PREFIX curl
    PATCH_COMMAND git apply ${PROJECT_SOURCE_DIR}/curl.patch
    CMAKE_ARGS "${CMAKE_ARGS}"
    )
