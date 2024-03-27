cmake_minimum_required(VERSION 3.27)
project(snake)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

# Dependencies
# find_package(raylib REQUIRED) # QUIET or REQUIRED
# if (NOT raylib_FOUND) # If there's none, fetch and build raylib
#     include(FetchContent)
#     FetchContent_Declare(
#             raylib
#             DOWNLOAD_EXTRACT_TIMESTAMP OFF
#             URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
#     )
#     FetchContent_GetProperties(raylib)
#     if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
#         set(FETCHCONTENT_QUIET NO)
#         FetchContent_Populate(raylib)
#         set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
#         add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
#     endif()
# endif()

# Our Project

add_executable(${PROJECT_NAME}
        main.cpp
        square.ixx
        playgame.cpp)
#set(raylib_VERBOSE 1)
include_directories(CMAKE_INCLUDE_PATH)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)