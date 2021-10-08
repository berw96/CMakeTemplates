set(CMAKE_VERBOSE_MAKEFILE ON)
cmake_minimum_required(VERSION 3.6)

# the project name is SDL_APP, rename as needed
project(SDL_APP CXX)

set(CMAKE_CXX_STANDARD 11)

if(WIN32)
    # use bundled version to save ourselves a lot of trouble
    set(SDL2MAIN_LIBRARY "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2main.lib")

    set(SDL2_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/libs/SDL2/include")
    set(SDL2_LIBRARY "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2.lib")
    
    # copy dynamic libraries
    file(COPY 
            "${CMAKE_SOURCE_DIR}/libs/SDL2/lib/x64/SDL2.dll"
            DESTINATION ${CMAKE_BINARY_DIR})
else()
    # let FindSDL2.cmake figure out where it is on Mac/Linux
    # Put the FindSDL2.cmake in ./cmake and tell CMake to find it there
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

    set(SDL2MAIN_LIBRARY "")

    find_package(SDL2 REQUIRED)
endif()

# include SDL header files
include_directories(${SDL2_INCLUDE_DIR})

# load user source and header files
file(GLOB_RECURSE SOURCE_FILES "src/*.h" "src/*.cpp")
add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})

# SDL2MAIN_LIBRARY is needed for Windows specific main function.
target_link_libraries(${PROJECT_NAME}
        ${SDL2MAIN_LIBRARY}
        ${SDL2_LIBRARY})
