// check if string is palindrome

#include <iostream>
#include <array>
#include <string>
#include <algorithm>

bool isPalindrome(std::string input_string)
{
  std::transform(input_string.begin(), input_string.end(), input_string.begin(), [](auto c) { return std::tolower(c); });

  std::string reversed_input_string{ input_string };
  std::reverse(reversed_input_string.begin(), reversed_input_string.end());

  return (input_string == reversed_input_string) ? true : false;
}

bool isPalindrome(char const *input_string)
{
  std::string reversed_input_string(input_string);
  std::reverse(reversed_input_string.begin(), reversed_input_string.end());
  return (input_string == reversed_input_string) ? true : false;
}

int main()
{
  std::string input_string{ "Abba" };
  // char const *input_string = "Hello, World!";

  if (isPalindrome(input_string))
  {
    std::cout << input_string << " is a palindrome!" << std::endl;
  } else
  {
    std::cout << input_string << " is not a palindrome!" << std::endl;
  }
}
