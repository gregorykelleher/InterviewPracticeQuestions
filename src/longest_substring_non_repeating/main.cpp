#include <iostream>
#include <string>
#include <unordered_map>

int find_substring_length(unsigned index, std::string input_string)
{
  std::string output_string{};
  std::unordered_map<char, bool> freq;

  for (unsigned pos{ index }; pos < input_string.length(); pos++)
  {
    if (freq.find(input_string[pos]) != freq.end())
    {
      break;
    }
    output_string.push_back(input_string[pos]);
    freq.insert({ input_string[pos], true });
  }
  return output_string.length();
}

int get_longest_non_repeating_substring(std::string input_string)
{
  int longest_substring_length{ 0 };

  if (input_string.length() <= 0)
  {
    return 0;
  }

  for (unsigned pos{ 0 }; pos < input_string.length(); pos++)
  {
    auto input_substring_length{ find_substring_length(pos, input_string) };

    if (longest_substring_length < input_substring_length)
    {
      longest_substring_length = input_substring_length;
    }
  }

  return longest_substring_length;
}

int main()
{
  std::cout << get_longest_non_repeating_substring("abcddcabda") << std::endl;
}