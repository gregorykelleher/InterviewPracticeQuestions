// find any anagrams between two strings

#include "anagram.hpp"

std::vector<std::string> extract_words(std::string const &str)
{
  std::istringstream stream(str);
  std::string word{};
  std::vector<std::string> words;

  while (getline(stream, word, ' '))
  {
    std::sort(word.begin(), word.end());
    words.push_back(word);
  }
  return words;
}

std::vector<std::string> findAnagram(std::string const &test_word, std::vector<std::string> const &word_vec)
{
    std::vector<std::string> found_anagrams{};

    for (auto const &curr_word : word_vec)
    {
        if ((curr_word.length() == test_word.length()) && (curr_word == test_word))
        {
            found_anagrams.push_back(curr_word);
        }
    }
    return found_anagrams;
}
