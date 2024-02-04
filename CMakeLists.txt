cmake_minimum_required(VERSION 3.0.0)
project(coro1 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(coro1 main.cpp)
target_compile_options(coro1 PUBLIC -std=c++20 -fcoroutines)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
