// return max number of water bottles to drink

#include <iostream>

int num_water_bottles(int num_bottles, int num_exchange)
{
  static int num_bottles_drank{ num_bottles };
  int num_bottles_exchanged{ num_bottles / num_exchange };

  num_bottles_drank += num_bottles_exchanged;

  if (num_bottles_exchanged != 0)
  {
    int empty_bottles{ num_bottles % num_exchange };
    num_bottles = num_bottles_exchanged + empty_bottles;

    num_water_bottles(num_bottles, num_exchange);
  }
  return num_bottles_drank;
}

int main()
{
  std::cout << "maximum number of water bottles to drink for 15 bottles (4 exchange): " << num_water_bottles(15, 4) << std::endl;

  return 0;
}
