cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/sys/cmake/toolchain.cmake")
project(Orichi VERSION 1.0 LANGUAGES ASM C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(config/config.cmake)

file(GLOB_RECURSE LUA_SOURCES_C ${PROJECT_SOURCE_DIR}/lib/lua-5.5.0/src/*.c)
add_library(lua STATIC ${LUA_SOURCES_C})

file(GLOB_RECURSE SOURCES_ASM ${PROJECT_SOURCE_DIR}/src/*.S)
file(GLOB_RECURSE SOURCES_C ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB_RECURSE SOURCES_CXX ${PROJECT_SOURCE_DIR}/src/*.cpp)
set(SOURCES ${SOURCES_ASM} ${SOURCES_C} ${SOURCES_CXX})
add_executable(${PROJECT_NAME} ${SOURCES})
include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(lib/nnheaders/include)
include_directories(lua PUBLIC lib/lua-5.5.0/src)

target_link_libraries(${PROJECT_NAME} PRIVATE lua)
target_link_options(${PROJECT_NAME} PRIVATE
		"-Wl,--defsym=__libc_malloc=malloc"
)

include(sys/cmake/module.cmake)
include(sys/cmake/deploy.cmake)
include(sys/cmake/sail.cmake)
usesail(${PROJECT_NAME})
