
#include <iostream>
#include <vector>

std::vector<std::string> fizz_buzz(int n)
{
  std::vector<std::string> container{};
  container.reserve(n);

  for (int i = 1; i <= n; i++)
  {
    std::string str{};

    if (i % 3 == 0 && i % 5 == 0)
    {
      str = "fizz-buzz";
    }
    else if (i % 3 == 0)
    {
      str = "fizz";
    }
    else if (i % 5 == 0)
    {
      str = "buzz";
    }
    else
    {
      str = std::to_string(i);
    }
    container.push_back(str);
  }
  return container;
}

int main()
{
  auto nums{ fizz_buzz(100) };

  for (auto val : nums)
  {
    std::cout << val << std::endl;
  }

  return 0;
}