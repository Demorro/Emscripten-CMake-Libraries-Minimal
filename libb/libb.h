#pragma once

#include "IAbstractInterface.h"

#ifdef _WIN32
  #ifdef LIBB_EXPORTS
    #define LIBB_API __declspec(dllexport)
  #else
    #define LIBB_API __declspec(dllimport)
  #endif
#else
  #define LIBB_API
#endif

LIBB_API void print_identifier_libb();
LIBB_API void print_identifier_libb_fromcommon();
LIBB_API void print_from_interface_libb(IAbstractInterface* interface);
  
