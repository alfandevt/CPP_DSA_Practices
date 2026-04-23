#include "node.h"

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
class LinkedList
{
private:
  Node *head;
  Node *tail;
  int length;

public:
  /* Constructor & Destructor */
  LinkedList(int);
  ~LinkedList();
  /* Information */
  void printHead();
  void printTail();
  void printLength();
  void printItems();
  /* CRUD */
  void append(int);
  void prepend(int);
  void deleteEnd();
  void deleteFirst();
  void deleteNode(int);
  void reverse();

  bool insert(int, int);
  bool set(int, int);

  /* Interview Questions */
  Node *getMiddleNode();
  Node *getMiddleNodeByLength();
  bool hasLoop();

  Node *get(int);
  Node *findKthFromTheEnd(int);
};
#endif