#include <emscripten/bind.h>
#include "commonlib.h"
#include "liba.h"
#include "libb.h"
#include "ConcreteInterfaceImplementation.h"

using namespace emscripten;

// This is what you get in the Module in JS-land
// Idea here is that we can still have formally split libraries in the rest of the codebase for non emscripten targets.
// We just pull them all together here in this module for WASM, avoiding any WASM complexity leaking out.
EMSCRIPTEN_BINDINGS(emscripten_bindings_module) {
  class_<IAbstractInterface>("IAbstractInterface")
  .function("print_interface", &IAbstractInterface::print_interface, pure_virtual());

  class_<ConcreteInterfaceImplementation, base<IAbstractInterface>>
  ("ConcreteInterfaceImplementation")
  .constructor<>();

  function("print_identifier_common", &print_identifier_common);
  function("print_identifier_liba", &print_identifier_liba);
  function("print_identifier_liba_fromcommon", &print_identifier_liba_fromcommon);
  function("print_identifier_libb", &print_identifier_libb);
  function("print_identifier_libb_fromcommon", &print_identifier_libb_fromcommon);
  function(
    "print_from_interface_libb",
    &print_from_interface_libb,
    allow_raw_pointers()   // <-- lets you pass IAbstractInterface* directly
  );
}
