cmake_minimum_required(VERSION 2.8)
project(FormatOutput CXX)

find_package(Git REQUIRED)

set(EXTERNAL_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external)
set(CMAKE_BUILD_TYPE "Debug")

execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init -- ${EXTERNAL_DIR}/cmake-conan)
include(${EXTERNAL_DIR}/cmake-conan/conan.cmake)

conan_cmake_run(REQUIRES fmt/6.2.1
                BASIC_SETUP CMAKE_TARGETS)

conan_cmake_run(REQUIRES boost/1.73.0
                BASIC_SETUP CMAKE_TARGETS)

add_executable(main main.cpp)
target_link_libraries(main CONAN_PKG::fmt CONAN_PKG::boost)