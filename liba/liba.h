#pragma once

#ifdef _WIN32
  #ifdef LIBA_EXPORTS
    #define LIBA_API __declspec(dllexport)
  #else
    #define LIBA_API __declspec(dllimport)
  #endif
#else
  #define LIBA_API
#endif

LIBA_API void print_identifier_liba();
LIBA_API void print_identifier_liba_fromcommon();
  

