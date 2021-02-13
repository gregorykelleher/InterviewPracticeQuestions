#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, int> get_substring_freq(std::string string_input)
{
  std::unordered_map<std::string, int> freq;

  for (unsigned curr_index{ 0 }; curr_index < string_input.length(); curr_index++)
  {
    if ((curr_index + 2) < string_input.length())
    {
      auto word{ string_input.substr(curr_index, 3) };

      if (freq.find(word) == freq.end())
      {
        freq.insert({ word, 1 });
      }
      else
      {
        freq[word] += 1;
      }
    }
  }

  return freq;
}

int main()
{
  for (auto const &pair : get_substring_freq("ABCCABC"))
  {
    std::cout << "word : " << pair.first << " freq : " << pair.second << std::endl;
  }

  return 0;
}
