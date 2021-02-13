// pretend stack

#include <iostream>
#include <sstream>
#include <stack>

bool is_number(const std::string &s)
{
  return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}

int solution(std::string input_string)
{
  std::stack<std::string> stack{};

  for (auto &letter : input_string)
  {
    std::ostringstream ostr;
    ostr << letter;
    std::string curr_letter{ ostr.str() };

    if (is_number(curr_letter))
    {
      stack.push(curr_letter);

    } else if (letter == '+')
    {
      auto sec_elem{ stack.top() };

      stack.pop();

      auto first_elem{ stack.top() };

      stack.pop();

      int sum{ std::stoi(sec_elem) + std::stoi(first_elem) };

      stack.push(std::to_string(sum));
    } else if (letter == '*')
    {
      auto sec_elem{ stack.top() };

      stack.pop();

      auto first_elem{ stack.top() };

      int sum{ std::stoi(sec_elem) * std::stoi(first_elem) };

      stack.pop();

      stack.push(std::to_string(sum));
    } else
    {
      return -1;
    }
  }

  if (!stack.empty())
  {
    return std::stoi(stack.top());
  }

  return -1;
}

int main()
{
  std::cout << solution("13+62*7+*");
}