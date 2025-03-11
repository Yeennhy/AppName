
# set(CMAKE_C_COMPILER gcc)
# set(CMAKE_CXX_COMPILER g++)

cmake_minimum_required(VERSION 3.10)
project(AppName)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add library dir
set(RAYLIB_PATH "./include/raylib")
link_directories(${RAYLIB_PATH}/lib)
include_directories(include)


# add source file
file (GLOB SRC "src/*.cpp")
file (GLOB MAIN "*.cpp")

# add all file to queue
set(SOURCE ${SRC} ${MAIN})

add_executable(AppName WIN32 ${SOURCE})

target_include_directories(AppName PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include" "${RAYLIB_PATH}/include")

target_link_libraries(AppName raylib -lopengl32 -lgdi32 -lwinmm)
