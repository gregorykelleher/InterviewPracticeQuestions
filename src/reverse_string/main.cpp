#include <iostream>
#include <sstream>
#include <algorithm>

std::string reverse_string(std::string input_string)
{
  std::string reversed_str{};
  std::transform(input_string.rbegin(), input_string.rend(), std::back_inserter(reversed_str), [](auto c) { return c; });

  return reversed_str;
}

// std::string reverse_string(std::string input_string)
// {
//   static std::string reversed_str{};

//   if (input_string.size() == 0)
//   {
//     return reversed_str;
//   }

//   auto last_character{ input_string.size() - 1 };

//   reversed_str += input_string[last_character];

//   return reverse_string(input_string.substr(0, last_character));
// }

// std::string reverse_string(std::string input_string)
// {
//   auto reversed_string{ input_string };
//   reverse(reversed_string.begin(), reversed_string.end());

//   return reversed_string;
// }

// std::string reverse_string(std::string input_string)
// {
//   std::istringstream stream{ input_string };

//   std::string word{};
//   std::string output_string{};

//   while (getline(stream, word, ' '))
//   {
//     reverse(word.begin(), word.end());
//     output_string.append(word + ' ');
//   }

//   return output_string;
// }

int main()
{
  std::cout << reverse_string("the quick brown fox jumps over the lazy dog") << std::endl;

  return 0;
}