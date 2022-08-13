project(error)

file(GLOB_RECURSE compiler_sources
    "src/*.cpp"
)

add_library(${PROJECT_NAME} ${compiler_sources})
add_library(mod::error ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
 PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)