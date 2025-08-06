#pragma once

#ifdef _WIN32
# ifdef COMMONLIB_EXPORTS
#   define COMMONLIB_API __declspec(dllexport)
# else
#   define COMMONLIB_API __declspec(dllimport)
# endif
#else
# define COMMONLIB_API
#endif

class COMMONLIB_API IAbstractInterface
{
 public:
  // Could these all be inline, and the type not exported? Perhaps ... although I worry that would ruin RTTI, at least on Windows.
  IAbstractInterface() noexcept;
  virtual ~IAbstractInterface() noexcept;
  IAbstractInterface(const IAbstractInterface&) noexcept;
  IAbstractInterface& operator=(const IAbstractInterface&) noexcept;
  
  virtual void print_interface() = 0;
};
