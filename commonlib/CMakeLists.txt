cmake_minimum_required(VERSION 3.10)
project(commonlib LANGUAGES CXX)

if(EMSCRIPTEN)
  add_library(commonlib OBJECT commonlib.cpp)
else()
  add_library(commonlib SHARED commonlib.cpp)
endif()

target_include_directories(commonlib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(commonlib PRIVATE COMMONLIB_EXPORTS)
