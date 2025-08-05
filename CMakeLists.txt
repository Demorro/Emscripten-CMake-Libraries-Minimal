cmake_minimum_required(VERSION 3.10)
project(CppLibrariesMinimalProj)

add_subdirectory(commonlib)
add_subdirectory(liba)
add_subdirectory(libb)

# Build an exercisor app for a regular build, and a bindings "project" for an emscripten one. See index.html at the root for exercising the bindings.
if(EMSCRIPTEN)
  add_subdirectory(emscriptenbindings)
else()
  add_subdirectory(app)
endif()
