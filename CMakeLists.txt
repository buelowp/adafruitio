cmake_minimum_required (VERSION 3.0.0 FATAL_ERROR)
project (adafruitio)

file (GLOB SOURCE "*.cpp")
file (GLOB HEADERS "*.h")

set (CMAKE_CXX_STANDARD 14)
set (CMAKE_INCLUDE_CURRENT_DIR ON)

add_library (${PROJECT_NAME} SHARED ${SOURCE})
target_link_libraries (${PROJECT_NAME} -lmosquittopp)

install (TARGETS ${PROJECT_NAME} DESTINATION /lib)
install (FILES ${HEADERS} DESTINATION /include)
