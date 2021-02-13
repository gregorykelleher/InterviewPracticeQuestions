// find if unsorted vector has duplicates

#include <algorithm>
#include <iostream>
#include <vector>

void removeDuplicates(std::vector<int> &nums)
{
  std::vector<int>::iterator iter{ nums.begin() };

  iter = std::unique(nums.begin(), nums.end());

  nums.resize(distance(nums.begin(), iter));

  for (auto &num : nums)
  {
    std::cout << num << std::endl;
  }
}

int main()
{
  std::vector<int> nums{ 4, 3, 4, 2 };

  auto isDuplicate = [](std::vector<int> nums) -> bool {
    std::sort(nums.begin(), nums.end());
    return (static_cast<unsigned>(distance(nums.begin(), std::unique(nums.begin(), nums.end()))) == nums.size()) ? false : true;
  };

  isDuplicate(nums);

  removeDuplicates(nums);
}