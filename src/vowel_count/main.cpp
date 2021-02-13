
#include <iostream>
#include <algorithm>

void calc_vowels_consonants(std::string &str)
{
  str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

  auto vowel_count{ 0 };
  auto consonant_count{ 0 };
  std::string vowels{ "aoieu" };

  for (auto const &character : str)
  {
    (std::find(vowels.begin(), vowels.end(), character) != vowels.end()) ? vowel_count++ : consonant_count++;
  }

  std::cout << "vowel count : " << vowel_count << std::endl;
  std::cout << "consonant_count : " << consonant_count << std::endl;
}

int main()
{
  std::string str{ "the quick brown fox jumps over the lazy dog" };
  calc_vowels_consonants(str);

  return 0;
}
