cmake_minimum_required(VERSION 3.10)

project(vfs_proj)

option(BUILD_ONLY_DOCS "Build only the docs" OFF)
if(BUILD_ONLY_DOCS)
    set(DOXYGEN_EXAMPLE_PATH ${PROJECT_SOURCE_DIR}/vfs/docs/)
    set(DOXYGEN_EXCLUDE_PATTERNS "main.cpp") # exclude example/main.cpp
    include(./vfs/cmake/Doxygen.cmake)
    enable_doxygen()
else()
    add_subdirectory(vfs)
    add_subdirectory(example)
endif()