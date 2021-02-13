// How many numbers are smaller than the current number

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> smallerNumbersThanCurrent(std::vector<int> nums)
{
  std::vector<int> result{};

  for (auto const &num : nums)
  {
    result.emplace_back(std::count_if(nums.begin(), nums.end(), [&num](auto curr) { return (curr != num && curr < num); }));
  }

  return result;
}

int main()
{
  auto result{ smallerNumbersThanCurrent({ 8, 1, 2, 2, 3 }) };

  for (auto const &value : result)
  {
    std::cout << value << std::endl;
  }

  return 0;
}
