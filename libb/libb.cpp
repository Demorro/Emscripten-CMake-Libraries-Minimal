#include "libb.h"
#include "commonlib.h"
#include <iostream>

void print_identifier_libb(){
  std::cout << "LibB" << std::endl;
}

void print_identifier_libb_fromcommon(){
  std::cout << "Calling common print from LibB" << std::endl;
  print_identifier_common();
}

void print_from_interface_libb(IAbstractInterface* interface)
{
  std::cout << "Calling print_interface from LibB" << std::endl;
  interface->print_interface();
}
