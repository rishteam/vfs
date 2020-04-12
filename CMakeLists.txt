cmake_minimum_required(VERSION 3.10)

project(vfs)

set(CMAKE_CXX_STANDARD 17)

if(MSYS)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "/mingw32/lib/cmake/SFML")
endif(MSYS)

# Add the executable
add_executable(vfs
    src/main.cpp
    src/fileSystem.cpp
    src/vfs.cpp
)
target_include_directories(vfs
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)
target_link_libraries(vfs
    sfml-system sfml-window sfml-graphics sfml-network sfml-audio
)

if(MSYS)
    target_link_libraries(vfs
        # For static libraries
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
        -mconsole
    )
endif(MSYS)