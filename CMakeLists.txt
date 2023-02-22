cmake_minimum_required(VERSION 3.21)

project(Cosmo VERSION 0.0.3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/install CACHE PATH "Install here" FORCE)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)
find_package(TGUI REQUIRED)    
find_package(Lua REQUIRED)

# build .exe
file(GLOB_RECURSE COSMO_SRC
        "src/*.h"
        "src/*.cpp")
        
include_directories(SYSTEM ./include)

add_executable(Cosmo ${COSMO_SRC})
target_link_libraries(Cosmo PRIVATE sfml-graphics tgui)
target_include_directories(Cosmo PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(Cosmo PRIVATE ${LUA_LIBRARIES})
add_definitions(-D_USE_MATH_DEFINES)

ADD_CUSTOM_COMMAND (TARGET Cosmo PRE_BUILD
        # copy resources to target dir
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/res $<TARGET_FILE_DIR:Cosmo>
        # output message
        COMMENT "Copying all files" VERBATIM)

install(TARGETS Cosmo DESTINATION . CONFIGURATIONS Release)
install(DIRECTORY res/ DESTINATION . CONFIGURATIONS Release)
install(IMPORTED_RUNTIME_ARTIFACTS tgui DESTINATION .)
install(IMPORTED_RUNTIME_ARTIFACTS sfml-system DESTINATION .)
install(IMPORTED_RUNTIME_ARTIFACTS sfml-graphics DESTINATION .)
install(IMPORTED_RUNTIME_ARTIFACTS sfml-window DESTINATION .)
install(IMPORTED_RUNTIME_ARTIFACTS sfml-audio DESTINATION .)
install(IMPORTED_RUNTIME_ARTIFACTS lua DESTINATION .)
set(CMAKE_INSTALL_SYSTEM_RUNTIME_DESTINATION .)
include(InstallRequiredSystemLibraries)

# Tell CPack to create a zip file.
set(CPACK_GENERATOR "ZIP")
# Tell CPack what to name the zip file. It will append `.zip`.
set(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}")
# Tell CPack not to put everything inside an enclosing directory.
set(CPACK_INCLUDE_TOPLEVEL_DIRECTORY OFF)
# Apparently this should be always on but isn't for backwards compatibility.
set(CPACK_VERBATIM_VARIABLES YES)

include(CPack)