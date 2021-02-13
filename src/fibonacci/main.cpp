
#include <iostream>

int get_fibonacci(int value)
{
  return (value <= 1) ? value : get_fibonacci(value - 1) + get_fibonacci(value - 2);
}

int main()
{
  std::cout << get_fibonacci(8) << std::endl;

  return 0;
}
