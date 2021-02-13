// Shuffle String

#include <iostream>
#include <vector>
#include <queue>
#include <map>

// solution using hash map
// std::string restoreString(std::string input_string, std::vector<int> &indices)
// {
//   std::map<int, char> output_map;

//   for (unsigned int index{ 0 }; index < indices.size(); index++)
//   {
//     output_map.insert(std::pair<int, char>{ indices[index], input_string[index] });
//   }

//   std::string output_string{};

//   for (auto iter{ output_map.begin() }; iter != output_map.end(); iter++)
//   {
//     output_string.push_back(iter->second);
//   }
//   return output_string;
// }

// solution using priority queue
std::string restoreString(std::string input_string, std::vector<int> &indices)
{
  using pair = std::tuple<int, char>;
  std::priority_queue<pair, std::vector<pair>, std::greater<pair>> output_queue{};

  auto index{ 0 };

  for (auto const &letter : input_string)
  {
    output_queue.push(std::make_pair(indices[index++], letter));
  }

  std::string output_string{};

  while (!output_queue.empty())
  {
    output_string.push_back(std::get<1>(output_queue.top()));
    output_queue.pop();
  }

  return output_string;
}

int main()
{
  std::vector<int> indices{ 4, 0, 2, 6, 7, 3, 1, 5 };

  std::cout << restoreString("aaiougrt", indices) << std::endl;

  return 0;
}
