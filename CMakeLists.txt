cmake_minimum_required(VERSION 3.22)
project(Project1)

set(CMAKE_CXX_STANDARD 14)

# Compiler warnings setup
if (MSVC)
    # MSVC: /W4 = lots of warnings, /WX = treat warnings as errors
    add_compile_options(/W4 /WX)
else()
    # GCC/Clang
    add_compile_options(-Wall -Werror)
endif()

# Pull in Catch2
Include(FetchContent)
FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.5.2
)
FetchContent_MakeAvailable(Catch2)

include_directories(src)

add_executable(Main
        src/main.cpp
        src/ProcessCommand.cpp
        src/Tree.cpp
)

add_executable(Tests
        test/test.cpp
        src/ProcessCommand.cpp
        src/Tree.cpp
)

target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(Tests)
