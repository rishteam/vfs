cmake_minimum_required(VERSION 3.10)

project(example1)

set(CMAKE_CXX_STANDARD 17)

if(MSYS)
    set(SFML_STATIC_LIBRARIES TRUE)
    set(SFML_DIR "/mingw32/lib/cmake/SFML")
endif(MSYS)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)
target_link_libraries(${PROJECT_NAME}
    sfml-system sfml-window sfml-graphics sfml-network sfml-audio
)

target_link_libraries(${PROJECT_NAME}
    vfs
)

if(MSYS)
    target_link_libraries(${PROJECT_NAME}
        # For static libraries
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
        -mconsole
    )
endif(MSYS)