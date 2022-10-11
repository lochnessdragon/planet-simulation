cmake_minimum_required(VERSION 3.10.0)

project(Planetary)

# if we aren't building in a repl install dependencies
if(NOT DEFINED ENV{REPL_ID})
    include(cmake/CPM.cmake)
    # raylib version 4.2.0
    CPMAddPackage("gh:raysan5/raylib#4.2.0") 
endif()

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(Planetary ${SOURCES})

# link libraries
target_link_libraries(Planetary raylib)

# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()