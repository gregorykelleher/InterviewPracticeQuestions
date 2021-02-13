// remove all duplicate numbers in sorted vector

#include <algorithm>
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int> &nums)
{
  std::vector<int>::iterator iter{ nums.begin() };

  iter = std::unique(nums.begin(), nums.end());

  nums.resize(distance(nums.begin(), iter));

  return nums.size();
}

int main()
{
  std::vector<int> nums{ 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };

  std::cout << "length of nums: " << removeDuplicates(nums) << std::endl;
}