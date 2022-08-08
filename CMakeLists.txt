cmake_minimum_required(VERSION 3.5)

project(joku)

add_definitions(
    -std=c++17
)

add_subdirectory(joku-cli)
add_subdirectory(joku-compiler)
add_subdirectory(joku-rt)

# add_executable(nvscript ${nvscript_sources})