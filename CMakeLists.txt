cmake_minimum_required(VERSION 3.9) 

# set variables
project(Cosmo VERSION 0.0.2)
set(CMAKE_CXX_STANDARD 17)

set(SFML_ROOT_PREFIX "C:/SFML-2.5.1" CACHE STRING "Root of SFML library. Must has include, lib and bin folder.")
set(TGUI_ROOT_PREFIX "C:/TGUI-0.8" CACHE STRING "Root of TGUI library. Must has include, lib and bin folder.")
set(SOL2_ROOT_PREFIX "C:/sol2-develop" CACHE STRING "Root of sol2 library. Must has include folder.")
set(LUA_ROOT_PREFIX "C:/Lua" CACHE STRING "Root of Lua. Must has include folder.")
set(LUA_DLL "C:/Lua/lua53.dll" CACHE STRING "Root of Lua. Must has include folder.")

set(SFML_DIR "${SFML_ROOT_PREFIX}/lib/cmake/SFML")
set(TGUI_DIR "${TGUI_ROOT_PREFIX}/lib/cmake/TGUI")

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
find_package(TGUI 0.8 REQUIRED)

# build .exe
file(GLOB_RECURSE COSMO_SRC
        "src/*.h"
        "src/*.cpp")

include_directories(${SOL2_ROOT_PREFIX}/single/include/sol)
include_directories(${LUA_ROOT_PREFIX}/include)
FIND_LIBRARY(liblua lua53 liblua53 ${LUA_ROOT_PREFIX})

add_executable(Cosmo ${COSMO_SRC})
target_link_libraries(Cosmo PRIVATE sfml-graphics tgui ${liblua})

# prepare target dir
set(SFML_DLL
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network)

set(TGUI_DLL
        tgui)

list(TRANSFORM SFML_DLL PREPEND ${SFML_ROOT_PREFIX}/bin/)
list(TRANSFORM TGUI_DLL PREPEND ${TGUI_ROOT_PREFIX}/bin/)

if (${CMAKE_BUILD_TYPE} STREQUAL "Debug")
    list(TRANSFORM SFML_DLL APPEND -d)
    list(TRANSFORM TGUI_DLL APPEND -d)
endif ()

list(TRANSFORM SFML_DLL APPEND -2)
set(COSMO_DLL ${SFML_DLL} ${TGUI_DLL})
list(TRANSFORM COSMO_DLL APPEND .dll)

ADD_CUSTOM_COMMAND (TARGET Cosmo PRE_BUILD
        # copy *.dll to target dir
        COMMAND ${CMAKE_COMMAND} -E copy ${COSMO_DLL} $<TARGET_FILE_DIR:Cosmo>
        COMMAND ${CMAKE_COMMAND} -E copy ${LUA_DLL} $<TARGET_FILE_DIR:Cosmo>
        # copy resources to target dir
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:Cosmo>
        # output message
        COMMENT "Copying all files" VERBATIM)