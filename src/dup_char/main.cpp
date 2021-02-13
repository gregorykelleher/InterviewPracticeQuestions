// remove all duplicate characters in a string

#include <iostream>
#include <unordered_map>

std::string str{ "bcabc" };

std::unordered_map<char, int> letter_freq;

int main()
{
  for (char &c : str)
  {
    auto is_letter_found = [c]() -> bool { return (letter_freq.find(c) == letter_freq.end() ? false : true); };

    if (is_letter_found())
    {
      letter_freq[c] += 1;
    }
    else if (is_letter_found() != true)
    {
      letter_freq.insert(std::pair(c, 1));
    }
  }

  for (auto const &pair : letter_freq)
  {
    if (pair.second > 1)
    {
      std::cout << "duplicate " << pair.first << ": " << pair.second << std::endl;
    }
  }
}