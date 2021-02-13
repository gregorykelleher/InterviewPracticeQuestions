// binary search tree

#include <iostream>

// Node definition
template<typename T>
class Tree
{

  struct Node {

    Node(T const &value)
      : value(value), left(nullptr), right(nullptr)
    {}

    T value;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
  };

public:
  Tree()
    : root(nullptr)
  {}

  void Insert(T const &value)
  {
    Insert(root, value);
  }

  void Display()
  {
    Display(root);
  }

  bool Search(T const &value)
  {
    return Search(root, value);
  }

private:
  std::unique_ptr<Node> root;

  bool Search(std::unique_ptr<Node> &node, T const &value)
  {
    if (!node)
    {
      return false;
    }
    if (node->value == value)
    {
      return true;
    }
    return Search((value < node->value) ? node->left : node->right, value);
  }

  void Display(std::unique_ptr<Node> &node)
  {
    if (node)
    {
      Display(node->left);
      std::cout << node->value << std::endl;
      Display(node->right);
    }
  }

  void Insert(std::unique_ptr<Node> &node, T const &value)
  {
    if (node)
    {
      Insert((value < node->value) ? node->left : node->right, value);
    } else
    {
      node = std::make_unique<Node>(value);
    }
  }
};

int main()
{
  Tree<int> tree{};
  tree.Insert(1);
  tree.Insert(2);
  tree.Insert(3);

  std::cout << "Search: " << tree.Search(5) << std::endl;

  tree.Display();
}