#include <iostream>
#include <vector>
#include <unordered_map>

// O(n^2)
// void get_sum_pair(std::vector<int> input, int sum)
// {
//   for (unsigned first_index{ 0 }; first_index < input.size(); first_index++)
//   {
//     for (unsigned second_index{ first_index }; second_index < input.size(); second_index++)
//     {
//       if (input[first_index] + input[second_index] == sum)
//       {
//         std::cout << "Pair is : "
//                   << "(" << input[first_index] << ", " << input[second_index] << ")" << std::endl;
//       }
//     }
//   }
// }

// O(n)
void get_sum_pair(std::vector<int> input, int sum)
{
  std::unordered_map<int, int> map{};

  for (auto const &curr_value : input)
  {
    if (map.find(sum - curr_value) != map.end())
    {
      std::cout << "Pair is : "
                << "(" << curr_value << ", " << (sum - curr_value) << ")" << std::endl;
    }
    map.insert({ curr_value, 0 });
  }
}

int main()
{

  std::vector input{ 1, 5, 7, -1 };

  get_sum_pair(input, 6);

  return 0;
}
