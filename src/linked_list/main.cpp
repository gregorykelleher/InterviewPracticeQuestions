// linked list

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct Node {
  int data;
  Node *next;

  Node(int const &data)
    : data{ data }, next{ nullptr }
  {}
};

class LinkedList
{
public:
  LinkedList()
    : head{ nullptr }
  {}

  void Display();
  void CountNumNodes();

  void InsertFront(int const &value);
  void InsertEnd(int const &value);
  void InsertAfterValue(int const &after_value, int const &value);

  void DeleteNode(int const &value);
  void DeleteDuplicates();

  Node *FindNode(int const &value);
  Node *FindMiddleNode();
  Node *Reverse(Node *first);
  bool IsPalindrome();
  void SwapNodes(int const &first_value, int const &second_value);

  Node *head;
};

Node *LinkedList::Reverse(Node *first)
{
  if (first == nullptr || first->next == nullptr)
  {
    return first;
  }
  auto rest{ LinkedList::Reverse(first->next) };

  first->next->next = first;
  first->next = nullptr;

  return rest;
}

void LinkedList::Display()
{
  auto curr_node{ head };

  while (curr_node != nullptr)
  {
    std::cout << "Node : " << curr_node->data << std::endl;

    if (curr_node->next != nullptr)
    {
      std::cout << "Node->next : " << curr_node->next->data << std::endl;
    }
    else
    {
      std::cout << "Node->next : nullptr" << std::endl;
    }

    std::cout << std::endl;

    curr_node = curr_node->next;
  }
}

void LinkedList::CountNumNodes()
{
  auto curr_node{ head };
  int count{ 0 };

  while (curr_node != nullptr)
  {
    count++;
    curr_node = curr_node->next;
  }
  std::cout << "number of nodes: " << count << std::endl;
}

void LinkedList::InsertFront(int const &value)
{
  auto new_node{ new Node(value) };

  if (head != nullptr)
  {
    new_node->next = head;
    head = new_node;
  }
  else
  {
    head = new_node;
  }
}

void LinkedList::InsertEnd(int const &value)
{
  auto curr_node{ head };
  auto new_node{ new Node(value) };

  if (head == nullptr)
  {
    head = new_node;
  }

  while (curr_node->next != nullptr)
  {
    curr_node = curr_node->next;
  }

  curr_node->next = new_node;
}

void LinkedList::DeleteNode(int const &value)
{
  auto curr_node{ head };

  // if the node to delete is the head
  if (curr_node->data == value)
  {
    auto node_to_delete{ curr_node };

    curr_node = curr_node->next;
    head = curr_node;

    free(node_to_delete);
  }

  while (curr_node->next != nullptr)
  {
    if (curr_node->next->data == value)
    {
      auto node_to_delete{ curr_node->next };

      curr_node->next = node_to_delete->next;

      free(node_to_delete);

      // if the next node is the end of the list
      if (curr_node->next == nullptr)
      {
        break;
      }
    }
    curr_node = curr_node->next;
  }
}

void LinkedList::DeleteDuplicates()
{
  std::unordered_map<int, bool> duplicates{};

  auto prev_node{ head };
  auto curr_node{ head->next };

  duplicates.insert(std::make_pair(prev_node->data, true));

  while (curr_node != nullptr)
  {
    if (duplicates.find(curr_node->data) == duplicates.end())
    {
      duplicates.insert(std::make_pair(curr_node->data, true));
      prev_node = curr_node;
      curr_node = curr_node->next;
    }
    else
    {
      auto node_to_delete{ curr_node };

      prev_node->next = node_to_delete->next;
      curr_node = node_to_delete->next;
      free(node_to_delete);
    }
  }
}

void LinkedList::InsertAfterValue(int const &after_value, int const &value)
{
  auto curr_node{ head };

  while (curr_node != nullptr)
  {
    if (curr_node->data == after_value)
    {
      auto new_node{ new Node(value) };

      new_node->next = curr_node->next;
      curr_node->next = new_node;
    }
    curr_node = curr_node->next;
  }
}

Node *LinkedList::FindNode(int const &value)
{
  auto curr_node{ head };

  while (curr_node != nullptr)
  {
    if (curr_node->data == value)
    {
      return curr_node;
    }
    curr_node = curr_node->next;
  }
  return nullptr;
}

Node *LinkedList::FindMiddleNode()
{
  if (head == nullptr)
  {
    return nullptr;
  }

  auto slow_pointer{ head }, fast_pointer{ head };

  while (fast_pointer->next->next != nullptr)
  {
    slow_pointer = slow_pointer->next;
    fast_pointer = fast_pointer->next->next;
  }

  return slow_pointer;
}

void LinkedList::SwapNodes(int const &first_value, int const &second_value)
{
  auto curr_node{ head };
  auto first_swap_node{ FindNode(first_value) };
  auto second_swap_node{ FindNode(second_value) };

  // if first and second values are in the linked list
  if (first_swap_node && second_swap_node != nullptr)
  {
    // save original first swap node data
    auto org_first_swap_node_data{ first_swap_node->data };

    // swap nodes
    first_swap_node->data = second_swap_node->data;
    second_swap_node->data = org_first_swap_node_data;

    // swap nodes next
    while (curr_node != nullptr && curr_node->next != nullptr)
    {
      if (curr_node->next->data == first_swap_node->data)
      {
        curr_node->next = first_swap_node;
      }
      if (curr_node->next->data == second_swap_node->data)
      {
        curr_node->next = second_swap_node;
      }
      curr_node = curr_node->next;
    }
  }
}

bool LinkedList::IsPalindrome()
{
  if (head == nullptr)
  {
    return false;
  }

  auto curr_node{ head };

  std::vector<int> palindrome{};

  while (curr_node != nullptr)
  {
    palindrome.emplace_back(curr_node->data);
    curr_node = curr_node->next;
  }

  std::vector<int> reversed_palindrome{};
  std::reverse_copy(palindrome.begin(), palindrome.end(), std::back_inserter(reversed_palindrome));

  return (palindrome == reversed_palindrome) ? true : false;
}

int main()
{
  LinkedList List{};

  List.InsertFront(3);
  List.InsertFront(2);
  List.InsertFront(1);

  List.InsertEnd(3);
  List.InsertEnd(2);
  List.InsertEnd(1);

  if (List.IsPalindrome())
  {
    std::cout << "list is a palindrome" << std::endl;
  }
  else
  {
    std::cout << "list is not a palindrome" << std::endl;
  }

  List.InsertAfterValue(2, 3);

  List.DeleteNode(3);

  List.DeleteDuplicates();

  List.head = List.Reverse(List.head);

  List.SwapNodes(3, 1);

  List.InsertEnd(4);
  List.InsertEnd(5);
  List.InsertEnd(6);

  List.Display();

  std::cout << "middle node is : " << List.FindMiddleNode()->data << std::endl;

  List.CountNumNodes();
}