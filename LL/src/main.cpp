#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
  LinkedList *myList = new LinkedList(2);
  myList->append(3);
  myList->append(4);
  myList->append(5);
  myList->prepend(1);
  myList->append(6);
  myList->printItems();
  myList->printLength();

  Node middle = *myList->getMiddleNode();
  Node KthItem = *myList->findKthFromTheEnd(1);
  std::cout << "Middle Node:" << middle.value << std::endl;
  std::cout << "KTH Item " << KthItem.value << std::endl;
  std::cout << "Has Loop? " << myList->hasLoop() << std::endl;

  return 0;
}