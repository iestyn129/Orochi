cmake_minimum_required(VERSION 3.16)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/sys/cmake/toolchain.cmake")
project(Orochi VERSION 1.0 LANGUAGES ASM C CXX)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)
include(config/config.cmake)

file(GLOB_RECURSE SOURCES_ASM ${PROJECT_SOURCE_DIR}/src/*.S)
file(GLOB_RECURSE SOURCES_C ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB_RECURSE SOURCES_CXX ${PROJECT_SOURCE_DIR}/src/*.cpp)
set(SOURCES ${SOURCES_ASM} ${SOURCES_C} ${SOURCES_CXX})
add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE
		${PROJECT_SOURCE_DIR}/include
		${PROJECT_SOURCE_DIR}/lib/nnheaders/include
)

FetchContent_Declare(
		lua
		GIT_REPOSITORY https://github.com/lua/lua.git
		GIT_TAG v5.4.8
		GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(lua)

file(GLOB_RECURSE LUA_SOURCES_C ${lua_SOURCE_DIR}/*.c)
add_library(lua STATIC
		${LUA_SOURCES_C}
)

target_include_directories(lua PUBLIC
		${lua_SOURCE_DIR}
)

target_compile_definitions(lua PRIVATE
		LUA_USE_APICHECK
)

FetchContent_Declare(
		sol2
		GIT_REPOSITORY https://github.com/ThePhD/sol2.git
		GIT_TAG v3.5.0
)

FetchContent_MakeAvailable(sol2)

target_link_libraries(${PROJECT_NAME} PRIVATE
		sol2::sol2
		lua
)

include(sys/cmake/module.cmake)
include(sys/cmake/deploy.cmake)
include(sys/cmake/sail.cmake)
usesail(${PROJECT_NAME})
