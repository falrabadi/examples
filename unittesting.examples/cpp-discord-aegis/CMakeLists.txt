cmake_minimum_required(VERSION 3.11)
project(example)

option(MSVC     "Using Visual Studio to build" ON)

find_package(Git)

if(NOT Git_FOUND)
  string(CONCAT GIT_NOT_FOUND_WARNING
    "GIT was not found, CMake list will likely fail. "
    "Please make sure that GIT is inside your PATH variable")
  message(WARNING ${GIT_NOT_FOUND_WARNING})
endif()

# Base on https://medium.com/analytics-vidhya/c-dependency-management-with-cmakes-fetchcontent-4ceca4693a5d
include(FetchContent)
FetchContent_Declare(aegis-cpp
  GIT_REPOSITORY "https://github.com/zeroxs/aegis.cpp.git"
  GIT_TAG "e033f7b894dd3e4ec60c9b1743745b86766fd8f4")

FetchContent_MakeAvailable(aegis-cpp)

add_executable(bot app.cpp)

target_link_libraries(bot aegis)
