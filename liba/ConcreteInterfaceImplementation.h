#pragma once

#include "IAbstractInterface.h"

#ifdef _WIN32
  #ifdef LIBA_EXPORTS
    #define LIBA_API __declspec(dllexport)
  #else
    #define LIBA_API __declspec(dllimport)
  #endif
#else
  #define LIBA_API
#endif

class LIBA_API ConcreteInterfaceImplementation : public IAbstractInterface
{
 public:
  void print_interface() override;
};
