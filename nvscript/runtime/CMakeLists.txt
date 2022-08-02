project(runtime)

file(GLOB runtime_sources
    "src/*.cpp"
)

add_library(${PROJECT_NAME} ${runtime_sources})
add_library(mod::rt ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
 PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)