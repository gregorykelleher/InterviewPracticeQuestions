#include <iostream>
#include <vector>
#include <unordered_map>

int find_most_freq_num(std::vector<int> input)
{
  std::unordered_map<int, int> freq{};

  for (auto const &val : input)
  {
    if (freq.find(val) == freq.end())
    {
      freq.insert({ val, 1 });
    }
    else
    {
      freq[val] += 1;
    }
  }

  std::pair<int, int> high_freq_num{ 0, 0 };

  for (auto const &pair : freq)
  {
    if (pair.second > high_freq_num.second)
    {
      high_freq_num.first = pair.first;
      high_freq_num.second = pair.second;
    }
  }

  return high_freq_num.first;
}

int main()
{
  std::vector<int> input{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10 };

  std::cout << "number with the highest frequency is : " << find_most_freq_num(input) << std::endl;

  return 0;
}
