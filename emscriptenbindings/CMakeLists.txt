cmake_minimum_required(VERSION 3.10)
project(emscriptenbindgings LANGUAGES CXX)

# The emscripten artifact is just one big static library, pull in the entire project to the emscripten module.
add_executable(emscriptenbindings
  $<TARGET_OBJECTS:commonlib>
  $<TARGET_OBJECTS:liba> 
  $<TARGET_OBJECTS:libb>
  bindings.cpp
)

set_target_properties(emscriptenbindings PROPERTIES
  ENABLE_EXPORTS TRUE
  POSITION_INDEPENDENT_CODE ON
)

# This lets us do what we do in bindings.cpp to have emscripten make us a nice module loader. (See index.js)
target_link_options(emscriptenbindings PRIVATE
  "-sMODULARIZE=1"
  "-sEXPORT_ES6=1"
  "--bind"
  "--no-entry"
)

target_link_libraries(emscriptenbindings PUBLIC commonlib liba libb)
