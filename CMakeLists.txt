cmake_minimum_required(VERSION 3.24)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# vcpkg toolchain
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(PROJECT FrozenSpace)
project(${PROJECT})

#libs
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
 find_package(ImGui-SFML CONFIG REQUIRED)


#src
add_subdirectory(src)