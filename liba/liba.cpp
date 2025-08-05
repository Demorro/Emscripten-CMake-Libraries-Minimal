#include "liba.h"
#include "commonlib.h"
#include <iostream>

void print_identifier_liba(){
  std::cout << "LibA" << std::endl;
}

void print_identifier_liba_fromcommon(){
  std::cout << "Calling common print from LibA" << std::endl;
  print_identifier_common();
}
