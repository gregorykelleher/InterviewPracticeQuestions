// find the frequency of every letter in a given string

#include <iostream>
#include <unordered_map>

std::unordered_map<char, int> letter_freq;
std::string str{ "the quick brown fox jumps over the lazy dog" };

int main()
{
  for (auto &curr_letter : str)
  {
    auto letter_found = [curr_letter]() -> bool { return (letter_freq.find(curr_letter) == letter_freq.end()) ? false : true; };

    if (letter_found())
    {
      letter_freq[curr_letter] += 1;
    }
    else if (!letter_found())
    {
      letter_freq.insert(std::make_pair(curr_letter, 1));
    }
  }

  for (auto const &pair : letter_freq)
  {
    std::cout << pair.first << ": " << pair.second << std::endl;
  }
}