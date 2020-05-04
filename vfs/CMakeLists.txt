cmake_minimum_required(VERSION 3.10)

option(CMAKE_BUILD_TYPE "Build Type" Debug)

project(vfs CXX)
include(cmake/StandardProjectSettings.cmake)
# Project option
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
  option(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
  if (ENABLE_BUILD_WITH_TIME_TRACE)
    add_compile_definitions(project_options INTERFACE -ftime-trace)
  endif()
endif()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# sanitizer options if supported by compiler
include(cmake/Sanitizers.cmake)
enable_sanitizers(project_options)

# enable doxygen
set(DOXYGEN_EXAMPLE_PATH ${PROJECT_SOURCE_DIR}/docs/)
include(cmake/Doxygen.cmake)
enable_doxygen()

# allow for static analysis options
include(cmake/StaticAnalyzers.cmake)

# Add the executable
add_library(vfs
    src/fileSystem.cpp
    src/vfs.cpp
)
target_include_directories(vfs
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(vfs project_options project_warnings)

if(MSYS)
    target_link_libraries(vfs
        # For static libraries
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
        -mconsole
    )
endif(MSYS)