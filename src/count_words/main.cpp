// count number of words in string

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

std::string str{ "the quick brown fox jumps over the lazy dog" };

int main()
{
  std::stringstream stream(str);
  std::string word{};
  int count{ 0 };

  while (getline(stream, word, ' '))
  {
    count++;
  }

  std::cout << count << std::endl;

  //   std::cout << std::count(str.cbegin(), str.cend(), ' ') + 1 << std::endl;
}
