cmake_minimum_required(VERSION 3.5)

project(joku)

add_definitions(
    -std=c++17
)

add_subdirectory(joku_cli)
add_subdirectory(compiler)
add_subdirectory(runtime)

# add_executable(nvscript ${nvscript_sources})