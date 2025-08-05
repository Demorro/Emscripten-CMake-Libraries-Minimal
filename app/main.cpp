#include <iostream>
#include "liba.h"
#include "libb.h"
#include "ConcreteInterfaceImplementation.h" //From LibA

int main()
{
  std::cout << "Application" << std::endl;
  print_identifier_liba();
  print_identifier_liba_fromcommon();
  
  print_identifier_libb();
  print_identifier_libb_fromcommon();

  // Do dynamic dispatch of a concrete type inside another lib
  // that does not have it as a dependency, via an interface
  // defined in a common, shared lib.

  //ConcreteInterfaceImplementation is defined in LibA, LibB does not know about it.
  IAbstractInterface* interface = new ConcreteInterfaceImplementation();
  print_from_interface_libb(interface);
  delete interface;
  
  return 0;
}
