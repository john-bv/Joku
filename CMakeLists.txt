cmake_minimum_required(VERSION 3.2)

project(nvscript)

set(SOURCES
    src/main.cpp
    src/compiler/lex/token.cpp
)

add_executable(nvscript ${SOURCES})

target_include_directories(nvscript
 PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)