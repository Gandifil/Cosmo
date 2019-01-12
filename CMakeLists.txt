cmake_minimum_required(VERSION 3.9) 

# set variables
project(Cosmo VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 14)

set(SFML_ROOT_PREFIX "C:/SFML" CACHE STRING "Root of SFML library. Must be include, lib and bin.")
set(TGUI_ROOT_PREFIX "C:/TGUI" CACHE STRING "Root of SFML library. Must be include, lib and bin.")

set(SFML_DIR "C:/SFML/lib/cmake/SFML")
set(TGUI_DIR "C:/TGUI/lib/cmake/TGUI")

file(GLOB_RECURSE COSMO_SRC
    "src/*.h"
    "src/*.cpp"
)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
find_package(TGUI 0.8 REQUIRED)

add_executable(Cosmo ${COSMO_SRC})
target_link_libraries(Cosmo PRIVATE sfml-graphics tgui)

add_custom_command(TARGET Cosmo PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:Cosmo>)

# copy dll to target directory

set(COSMO_BIN_DLL
        sfml-system
        sfml-window
        sfml-graphics
        sfml-audio
        sfml-network
        )

list(TRANSFORM COSMO_BIN_DLL PREPEND ${SFML_ROOT_PREFIX}/bin/)
set(COSMO_BIN_DLL_DEBUG ${COSMO_BIN_DLL})
list(TRANSFORM COSMO_BIN_DLL APPEND -2.dll)
list(TRANSFORM COSMO_BIN_DLL_DEBUG APPEND -d-2.dll)

MESSAGE(${COSMO_BIN_DLL})

ADD_CUSTOM_COMMAND (TARGET Cosmo PRE_BUILD
        # DEBUG
        COMMAND ${CMAKE_COMMAND} -E copy ${TGUI_ROOT_PREFIX}/bin/tgui-d.dll $<TARGET_FILE_DIR:Cosmo>
        COMMAND ${CMAKE_COMMAND} -E copy ${COSMO_BIN_DLL_DEBUG} $<TARGET_FILE_DIR:Cosmo>

        # RELEASE
        COMMAND ${CMAKE_COMMAND} -E copy ${TGUI_ROOT_PREFIX}/bin/tgui.dll $<TARGET_FILE_DIR:Cosmo>
        COMMAND ${CMAKE_COMMAND} -E copy ${COSMO_BIN_DLL} $<TARGET_FILE_DIR:Cosmo>

        # Output Message
        COMMENT "Copying Engines binaries" VERBATIM)