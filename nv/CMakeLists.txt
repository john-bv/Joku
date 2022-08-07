project(nv)

file(GLOB nv_sourcefiles
    "src/*.cpp"
)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        ${CMAKE_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME}
    mod::compiler
    mod::rt
)