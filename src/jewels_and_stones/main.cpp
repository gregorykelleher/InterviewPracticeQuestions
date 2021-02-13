// Jewels and Stones

#include <iostream>
#include <map>

int num_jewels_in_stones(std::string jewels, std::string stones)
{
  auto count{ 0 };

  for (auto const &jewel : jewels)
  {
    count += std::count_if(stones.begin(), stones.end(), [&jewel](auto stone) { return stone == jewel; });
  }

  return count;
}

// int num_jewels_in_stones(std::string jewels, std::string stones)
// {
//   std::map<char, int> stone_freq{};

//   for (auto const &stone : stones)
//   {
//     if (stone_freq.find(stone) == stone_freq.end())
//     {
//       stone_freq.emplace(stone, 1);
//     }
//     else
//     {
//       stone_freq[stone] += 1;
//     }
//   }

//   auto jewel_count{ 0 };

//   for (auto const &jewel : jewels)
//   {
//     if (stone_freq.find(jewel) != stone_freq.end())
//     {
//       jewel_count += stone_freq[jewel];
//     }
//   }

// return jewel_count;
// }

int main()
{
  std::cout << num_jewels_in_stones("aAb", "bbbb") << std::endl;
  return 0;
}
