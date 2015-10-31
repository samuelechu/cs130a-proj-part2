#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

template < typename T >
class List {
 public:
  
  // Default constructor
 List(): size(0) { head = NULL;}
  
  
struct Node {

    T value;
    Node *next;
    Node *prev;
    Node(T t, Node* n, Node * p) : value(t), next(n), prev(p) {}

};

  
  ~List() { deleteList(head); }

void insert (int pos, const T & item);
/* Inserts the item right before position pos, growing the list by
pos must be between 0 and the current length of the list.
(feel free return bool, if you want.) */

void remove (int pos);

/* Removes the element at position pos, shrinking the list by 1.
   pos must be between 0 and the current length of the list minus 1*/

void set (int pos, const T & item);
/* overwrites position pos in the list with item.
Does not change the length of the list.
pos must be between 0 and the current length of the list minus 1*/


T const & get (int pos) const;
/* returns the item at position pos, not changing the list.
pos must be between 0 and the current length of the list minus 1*/

 
  

  void printList();
  void deleteList(Node *n);
  
  int getSize() const{ return getSize(head); }

  Node* getHead(){return head;}
  
  
 private:

  int size;
  Node* head;

  
  void deleteNode(Node *n);
  
  
  int getSize(const Node *n) const;
  
  Node* getNode(int pos) const;
  
};

#include "List.cpp"
#endif
