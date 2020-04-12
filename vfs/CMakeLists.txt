cmake_minimum_required(VERSION 3.10)

project(vfs)

set(CMAKE_CXX_STANDARD 17)

# Add the executable
add_library(vfs
    src/fileSystem.cpp
    src/vfs.cpp
)
target_include_directories(vfs
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

if(MSYS)
    target_link_libraries(vfs
        # For static libraries
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
        -mconsole
    )
endif(MSYS)