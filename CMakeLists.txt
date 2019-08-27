project(adaio)

cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

include_directories(${Qt5Core_INCLUDE_DIRS} ${CMAKE_CURRENT_BINARY_DIR})

set(adaio_SRCS adaio.cpp main.cpp)

add_executable(adaio ${adaio_SRCS})
target_link_libraries(adaio -lmosquittopp)

install(TARGETS adaio RUNTIME DESTINATION bin)
