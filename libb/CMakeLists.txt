cmake_minimum_required(VERSION 3.10)
project(libb LANGUAGES CXX)

if(EMSCRIPTEN)
  add_library(libb OBJECT
    libb.cpp
  )
else()
  add_library(libb SHARED libb.cpp)
endif()

target_link_libraries(libb PUBLIC commonlib)
target_include_directories(libb PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(libb PRIVATE LIBB_EXPORTS)
