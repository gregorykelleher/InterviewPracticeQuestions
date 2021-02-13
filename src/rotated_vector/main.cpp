#include <iostream>
#include <vector>
#include <algorithm>

bool is_rotated(std::vector<int> first_input, std::vector<int> second_input)
{
  auto rotation_point{ 0 };

  for (unsigned index{ 0 }; index < first_input.size(); index++)
  {
    rotation_point = (first_input[index] == second_input[0]) ? index : rotation_point;
  }

  std::rotate(first_input.begin(), first_input.begin() + rotation_point, first_input.end());

  return (first_input == second_input) ? true : false;
}
int main()
{
  std::vector<int> first_input{ 1, 2, 3, 4, 5, 6, 7, 8 };
  std::vector<int> second_input{ 5, 6, 7, 8, 1, 2, 3, 4 };

  if (is_rotated(first_input, second_input))
  {
    std::cout << "the second input is a rotation of the first input" << std::endl;
  }
  else
  {
    std::cout << "the second input is not a rotation of the first input" << std::endl;
  }

  return 0;
}
