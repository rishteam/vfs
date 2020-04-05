cmake_minimum_required(VERSION 3.10)

project(vfs
    VERSION 0.0.1
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

# Add static library
add_library(mylib STATIC
	src/icejj.cpp
	src/fileSystem.cpp
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
        # For static libraries
        -static-libgcc -static-libstdc++ -lwsock32 -lws2_32
        -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive
    )
endif(MSYS)

if(MSVC)
    target_link_libraries(vfs
        mylib
    )
endif(MSVC)