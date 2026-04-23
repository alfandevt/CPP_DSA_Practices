#include <iostream>
#include <string>
#include <cmath>
#include "linked_list.h"

/* Constructor & Destructor */
LinkedList::LinkedList(int value)
{
  Node *newNode = new Node(value);
  head = newNode;
  tail = newNode;
  length = 1;
}
LinkedList::~LinkedList()
{
  Node *temp = head;
  while (head)
  {
    head = head->next;
    delete temp;
    temp = head;
  }
};
/* Information */
void LinkedList::printHead()
{
  Node *temp = head;
  std::cout << "Head: " << temp << std::endl;
}
void LinkedList::printTail()
{
  Node *temp = tail;
  std::cout << "Tail: " << temp << std::endl;
}
void LinkedList::printLength()
{
  int len = length;
  std::cout << "Length: " << len << std::endl;
}
void LinkedList::printItems()
{
  Node *temp = head;
  std::string text;
  while (temp)
  {
    text += std::to_string(temp->value);
    text += temp->next ? "->" : "";
    temp = temp->next;
  }
  std::cout << "LinkedList Items: " << text << std::endl;
}
/* CRUD */
void LinkedList::append(int value)
{
  Node *newNode = new Node(value);
  if (length == 0)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    tail->next = newNode;
    tail = newNode;
  }
  length++;
}
void LinkedList::prepend(int value)
{
  Node *newNode = new Node(value);
  if (length == 0)
  {
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->next = head;
    head = newNode;
  }
  length++;
}
void LinkedList::deleteEnd()
{
  if (length == 0)
    return;
  Node *temp = head;
  if (length == 1)
  {
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    Node *pre = head;
    while (temp->next)
    {
      pre = temp;
      temp = temp->next;
    }
    tail = pre;
    tail->next = nullptr;
  }
  delete temp;
  length--;
}
void LinkedList::deleteFirst()
{
  if (length == 0)
    return;
  Node *temp = head;
  if (length == 1)
  {
    head = nullptr;
    tail = nullptr;
  }
  else
  {
    head = head->next;
  }
  delete temp;
  length--;
}
void LinkedList::deleteNode(int index)
{
  if (index < 0 || index >= length)
    return;
  if (index == 0)
    return deleteFirst();
  if (index == length - 1)
    return deleteEnd();

  Node *prev = get(index - 1);
  Node *temp = prev->next;

  prev->next = temp->next;
  delete temp;
  length--;
}
void LinkedList::reverse()
{
  Node *temp = head;
  head = tail;
  tail = temp;

  Node *before = nullptr;
  Node *after = temp->next;

  for (int i = 0; i < length; i++)
  {
    after = temp->next;
    temp->next = before;
    before = temp;
    temp = after;
  }
}
Node *LinkedList::get(int index)
{
  if (index < 0 || index > length)
  {
    return nullptr;
  }
  Node *temp = head;
  for (int i = 0; i < index; i++)
  {
    temp = temp->next;
  }
  return temp;
}
bool LinkedList::set(int index, int value)
{
  Node *temp = get(index);
  if (temp)
  {
    temp->value = value;
    return true;
  }
  return false;
}
bool LinkedList::insert(int index, int value)
{

  if (index < 0 || index > length)
    return false;

  if (index == 0)
  {
    prepend(value);
    return true;
  }

  if (index == length)
  {
    append(value);
    return true;
  }

  Node *newNode = new Node(value);
  Node *temp = get(index - 1);

  newNode->next = temp->next;
  temp->next = newNode;
  length++;

  return true;
}
/* Interview Question */
Node *LinkedList::getMiddleNode()
{
  if (!head && !tail)
    return nullptr;
  Node *slow = head;
  Node *fast = head;
  while (fast->next && fast->next->next)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}
Node *LinkedList::getMiddleNodeByLength()
{
  int middle = ceil(length / 2);
  return get(middle);
}
Node *LinkedList::findKthFromTheEnd(int k)
{
  if(!head || k <= 0) return nullptr;
  Node *fast = head;
  Node *slow = head;
  for (int i = 0; i < k; i++)
  {
    if(!fast) return nullptr;
    fast = fast->next;
  }

  while(fast)
  {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}
bool LinkedList::hasLoop()
{
  Node *fast = head;
  Node *slow = head;
  while (fast && fast->next)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}


