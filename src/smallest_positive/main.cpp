#include <iostream>
#include <vector>
#include <algorithm>

int find_missing_positive(std::vector<int> &nums)
{
  auto ans{ 1 };

  sort(nums.begin(), nums.end());

  for (auto &elem : nums)
  {
    if (elem == ans)
    {
      ans++;
    }
  }
  return ans;
}

int main()
{
  std::vector<int> nums{ 3, 4, -1, 1 };
  std::cout << find_missing_positive(nums) << std::endl;
}