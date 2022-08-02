project(nv)

file(GLOB nv_sourcefiles
    "src/*.cpp"
)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    mod::rt
    mod::compiler
)