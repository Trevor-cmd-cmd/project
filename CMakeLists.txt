cmake_minimum_required(VERSION 3.16)

project(MyEngine C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

file(GLOB_RECURSE ENGINE_OPENGL_SOURCES
    CONFIGURE_DEPENDS
    tinyGE/src/*.cpp
    tinyGE/src/*.c
    tinyGE/thirdparty/glad/*.c
)

# Skip precompiled headers for C sources (they cannot include C++ headers)
file(GLOB_RECURSE ENGINE_C_SOURCES
    CONFIGURE_DEPENDS
    tinyGE/src/*.c
    tinyGE/thirdparty/glad/*.c
)

if(ENGINE_C_SOURCES)
    set_source_files_properties(${ENGINE_C_SOURCES} PROPERTIES SKIP_PRECOMPILE_HEADERS ON)
endif()

add_library(tinyGE STATIC
    ${ENGINE_OPENGL_SOURCES}
)
set_target_properties(tinyGE PROPERTIES
    OUTPUT_NAME tinyGE    
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/tinyGE/src/core
)

target_include_directories(tinyGE PUBLIC
    
    ${CMAKE_CURRENT_SOURCE_DIR}/tinyGE/include
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/tinyGE/thirdparty
    ${CMAKE_CURRENT_SOURCE_DIR}/tinyGE/include/core
    ${CMAKE_CURRENT_SOURCE_DIR}/tinyGE/include/graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/tinyGE/include/components
)

# Precompiled header for tinyGE
target_precompile_headers(tinyGE PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/tinyGE/include/core/pch.h
)

target_link_libraries(tinyGE PUBLIC
    OpenGL::GL
    glfw
    dl
)

add_executable(MyEngine
    sandbox/snadboc.cpp
)

target_include_directories(MyEngine PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/opengl/include
    ${CMAKE_CURRENT_SOURCE_DIR}/opengl/thirdparty
)

target_link_libraries(MyEngine PRIVATE
    tinyGE
)

set_target_properties(MyEngine PROPERTIES
    OUTPUT_NAME main
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/sandbox
)
