// input is "Hello" output is "Holle". All vowels should be replaced by in reverse order

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

bool isVowel(char letter)
{
  std::array<char, 5> vowels{ 'a', 'e', 'i', 'o', 'u' };

  for (auto const &vowel : vowels)
  {
    if (letter == vowel)
    {
      return true;
    }
  }

  return false;
}

std::vector<char> getVowelPattern(std::string input_string)
{
  std::vector<char> vowel_pattern{};

  for (auto &letter : input_string)
  {
    if (isVowel(letter))
    {
      vowel_pattern.emplace_back(letter);
    }
  }
  return vowel_pattern;
}

std::string getReversedVowelSequence(std::vector<char> vowel_pattern, std::string &input_string)
{
  std::reverse(vowel_pattern.begin(), vowel_pattern.end());

  // for (auto const &vowel : vowel_pattern)
  // {
  //   for (auto &letter : input_string)
  //   {
  //     if (isVowel(letter))
  //     {
  //       std::replace(input_string.begin(), input_string.end(), letter, vowel);
  //     }
  //   }
  // }

  return input_string;
}

int main()
{
  std::string input_string{ "Hello" };

  auto const vowel_pattern{ getVowelPattern(input_string) };

  auto const reversed_vowel_sequence{ getReversedVowelSequence(vowel_pattern, input_string) };

  std::cout << reversed_vowel_sequence << std::endl;
}