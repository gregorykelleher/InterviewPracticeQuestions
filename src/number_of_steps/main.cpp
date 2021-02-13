// Number of steps reduce to zero

#include <iostream>

int number_of_steps(int num)
{
  auto num_steps{ 0 };

  while (num != 0)
  {
    (num % 2 == 0) ? (num = num / 2) : (num = num - 1);
    num_steps++;
  }

  return num_steps;
}

int main()
{
  std::cout << number_of_steps(123) << std::endl;

  return 0;
}
