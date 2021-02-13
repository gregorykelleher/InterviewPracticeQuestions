// format string into grouping

#include <array>
#include <algorithm>
#include <iostream>

void RemoveSpecialChars(std::string &input_string)
{
  input_string.erase(std::remove(input_string.begin(), input_string.end(), '-'), input_string.end());
  input_string.erase(std::remove(input_string.begin(), input_string.end(), ' '), input_string.end());
}

std::string FormatString(std::string input_string)
{
  RemoveSpecialChars(input_string);
  std::string output_string{};

  while (input_string.length() >= 5)
  {
    output_string.append(input_string.substr(0, 3) + " ");
    input_string = input_string.substr(3, input_string.length());
  }

  while (input_string.length() != 0)
  {
    if (input_string.length() % 2 == 0)
    {
      output_string.append(input_string.substr(0, 2) + " ");
      input_string = input_string.substr(2, input_string.length());
    }
  }

  return output_string;
}

int main()
{
  std::cout << FormatString("AA-44 BB 55CD 83FG") << std::endl;
}
