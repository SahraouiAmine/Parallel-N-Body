cmake_minimum_required(VERSION 4.2)
project(parallel_NBody)

set(CMAKE_CXX_STANDARD 20)

add_executable(parallel_NBody)
add_library(NBody_lib)

target_sources(parallel_NBody
    PRIVATE
        src/main.cpp)

target_sources(NBody_lib
        PRIVATE
            src/domain.cpp
            src/io.cpp
            src/physics.cpp

        PUBLIC
            FILE_SET headers
            TYPE HEADERS
            BASE_DIRS
                include
            FILES
                include/domain.hpp
                include/io.hpp
                include/physics.hpp
                include/types.hpp
)

target_link_libraries(parallel_NBody
    PRIVATE
        NBody_lib)
