// find first non-repeating character in a string

#include <iostream>
#include <map>

int main()
{
  std::string str{ "GeeksforGeeks" };
  std::map<char, int> letter_freq;

  for (auto const &letter : str)
  {
    if (letter_freq.find(letter) != letter_freq.end())
    {
      letter_freq.emplace(letter, 1);
    }
    letter_freq[letter] += 1;
  }

  for (auto const &letter : letter_freq)
  {
    if (letter.second < 2)
    {
      std::cout << "first non-repeating character is : " << letter.first << std::endl;
      break;
    }
  }
}