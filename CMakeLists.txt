cmake_minimum_required(VERSION 3.10)

project(vfs)

if(MSYS)
    set(SFML_STATIC_LIBRARIES TRUE)
endif(MSYS)

set(CMAKE_CXX_STANDARD 17)

if(MSYS)
    set(SFML_DIR "/mingw32/lib/cmake/SFML")
endif(MSYS)

# Add static library
add_library(mylib STATIC
	src/icejj.cpp
    src/fileSystem.cpp
    src/vfs.cpp
)
target_include_directories(mylib
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

# Add the executable
add_executable(vfs
	src/main.cpp
)
target_include_directories(vfs
    PRIVATE ${PROJECT_SOURCE_DIR}/include
)

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)

target_link_libraries(vfs
    sfml-system sfml-window sfml-graphics sfml-network sfml-audio
)

file(COPY ${CMAKE_SOURCE_DIR}/test DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})

if(APPLE)
    target_link_libraries(vfs
        mylib
    )
endif(APPLE)

if(MSYS)
    target_link_libraries(vfs
        mylib
        sfml-graphics sfml-audio
        # For static libraries
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
        -mconsole
    )
endif(MSYS)

if(MSVC)
    target_link_libraries(vfs
        mylib
    )
endif(MSVC)