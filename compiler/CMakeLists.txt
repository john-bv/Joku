project(compiler)

file(GLOB_RECURSE compiler_sources
    "src/*.cpp"
)

# file(GLOB_RECURSE compiler_headers
#     "src/*.h"
# )
# file(GLOB compiler_headers
#     "include/**/*.h"
#     "include/**/*.hpp"
# )

add_library(${PROJECT_NAME} ${compiler_sources})
add_library(mod::compiler ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
 PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)