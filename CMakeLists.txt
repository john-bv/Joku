cmake_minimum_required(VERSION 3.5)

project(nvscript)

add_subdirectory(nv)
add_subdirectory(compiler)
add_subdirectory(runtime)

# add_executable(nvscript ${nvscript_sources})