#pragma once

class IAbstractInterface
{
 public:
  virtual ~IAbstractInterface() = default;
  virtual void print_interface() = 0;
};
