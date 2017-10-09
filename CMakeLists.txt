cmake_minimum_required(VERSION 2.8)

project(vercert C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic")

find_package(CURL)
add_executable(vercert vercert.c)
target_include_directories(vercert PRIVATE ${CURL_INCLUDE_DIRS})
target_link_libraries(vercert ${CURL_LIBRARIES})
