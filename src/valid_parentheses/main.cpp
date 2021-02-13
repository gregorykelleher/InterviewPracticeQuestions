#include <iostream>
#include <stack>

bool is_valid_parentheses(std::string input)
{
  std::string opening_parentheses{ "[{(" };
  std::string closing_parentheses{ ")}]" };

  std::stack<char> stack{};

  if (input.size() % 2 != 0)
  {
    return false;
  }

  for (auto const &current_parenthesis : input)
  {
    if (opening_parentheses.find(current_parenthesis) != std::string::npos)
    {
      stack.push(current_parenthesis);
    }
    else if (closing_parentheses.find(current_parenthesis) != std::string::npos)
    {
      if (stack.size() == 0)
      {
        return false;
      }

      if ((stack.top() == '(' && current_parenthesis != ')')
          || (stack.top() == '{' && current_parenthesis != '}')
          || (stack.top() == '[' && current_parenthesis != ']'))
      {
        return false;
      }

      stack.pop();
    }
  }
  return (stack.size() == 0) ? true : false;
}

int main()
{
  if (is_valid_parentheses("((}))"))
  {
    std::cout << "valid parentheses" << std::endl;
  }
  else
  {
    std::cout << "invalid parentheses!" << std::endl;
  }

  return 0;
}
