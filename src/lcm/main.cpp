#include <iostream>

void get_lcm(int first_multiple, int second_multiple)
{
  auto max_divisible{ (first_multiple > second_multiple) ? first_multiple : second_multiple };

  while (1)
  {
    if (max_divisible % first_multiple == 0 && max_divisible % second_multiple == 0)
    {
      std::cout << "lcm is " << max_divisible << std::endl;
      break;
    }
    else
    {
      max_divisible++;
    }
  }
}

int main()
{
  get_lcm(4, 19);

  return 0;
}
