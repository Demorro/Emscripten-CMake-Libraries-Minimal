cmake_minimum_required(VERSION 3.10)
project(liba LANGUAGES CXX)

if(EMSCRIPTEN)
  add_library(liba OBJECT
    liba.cpp
    ConcreteInterfaceImplementation.cpp
  )
else()
  add_library(liba SHARED liba.cpp ConcreteInterfaceImplementation.cpp)
endif()

target_link_libraries(liba PRIVATE commonlib)
target_include_directories(liba PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_definitions(liba PRIVATE LIBA_EXPORTS)

