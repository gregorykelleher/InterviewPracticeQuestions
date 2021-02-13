#include <iostream>
#include <vector>

// int calc_max_profit(std::vector<int> prices)
// {
//   auto max_profit{ 0 };
//   auto min_buy{ INT_MAX };

//   for (unsigned index{ 0 }; index < prices.size(); index++)
//   {
//     min_buy = std::min(min_buy, prices[index]);
//     max_profit = std::max(max_profit, prices[index] - min_buy);
//   }
//   return max_profit;
// }

int calc_max_profit(std::vector<int> prices)
{
  auto max_profit{ 0 };

  for (unsigned min_index{ 0 }; min_index < prices.size(); min_index++)
  {
    auto min_buy{ prices[min_index] };

    for (unsigned max_index{ min_index }; max_index < prices.size(); max_index++)
    {
      auto max_sell{ prices[max_index] };

      auto profit{ max_sell - min_buy };

      max_profit = (profit > max_profit) ? profit : max_profit;
    }
  }

  return max_profit;
}

int main()
{
  auto ans{ calc_max_profit({ 7, 1, 5, 3, 6, 4 }) };

  std::cout << "max profit is " << ans << std::endl;

  return 0;
}
