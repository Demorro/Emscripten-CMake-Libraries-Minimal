#pragma once

#ifdef _WIN32
  #ifdef COMMONLIB_EXPORTS
    #define COMMONLIB_API __declspec(dllexport)
  #else
    #define COMMONLIB_API __declspec(dllimport)
  #endif
#else
  #define COMMONLIB_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

  COMMONLIB_API void print_identifier_common();

#ifdef __cplusplus
}
#endif
