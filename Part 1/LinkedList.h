#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>

template < typename T >
class LinkedList {
 public:
  
  // Default constructor
  LinkedList() { head = tail = NULL; }
  
  
struct Node {

    T value;
    Node *next;
    Node *prev;
    Node(T t, Node* n, Node * p) : value(t), next(n), prev(p) {}

};
    

  //stream output operator
  friend std::ostream& operator<< (std::ostream& strm, const LinkedList<T>& list) {
    list.printList(list.head,strm);
    return strm;
  }

  
  ~LinkedList() { deleteList(head); }
  
  void insert(const T &value){ 
    if(!head) {
      head = new Node(value, NULL, NULL);
      tail = head;
    }
    else
      insert(tail, value); 
  }


  void deleteValue(const T &value){

    Node *found = find(value);

    if(found)
      deleteNode(found);


  }

  void deleteList(Node *n);
  void deleteNode(Node *n);
  void deleteAtNdx(int index);
  
  //T* find(const T& value) const { return find(root, value); }
  int getSize() const{ return getSize(head); }

  Node* getHead(){return head;}
 private:


  Node* head;
  Node* tail;

  // Given
  void printList(const Node *n, std::ostream &os) const;
  
  void insert(Node *n, const T& v);
  int getSize(const Node *n) const;
  
  Node* find(const T& v);
  
};

#include "LinkedList.cpp"
#endif
#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include "Node.h"

template < typename T >
class LinkedList {
 public:
  
  // Default constructor
  LinkedList() { head = tail = NULL; }
  
  /*
struct Node {

    T value;
    Node *next;
    Node *prev;
    Node(T t, Node* n, Node * p) : value(t), next(n), prev(p) {}

    };*/
    

  //stream output operator
  friend std::ostream& operator<< (std::ostream& strm, const LinkedList<T>& list) {
    list.printList(list.head,strm);
    return strm;
  }

  
  ~LinkedList() { deleteList(head); }


  void deleteList(Node<T> *n);
  
  void insert(const T &value){ 
    if(!head) {
      head = new Node<T>(value, NULL, NULL);
      tail = head;
    }
    else
      insert(tail, value); 
  }


  void deleteValue(const T &value){

    Node<T> *found = find(value);

    if(found)
      deleteNode(found);


  }

  void deleteNode(Node<T> *n);
  void deleteAtNdx(int index);
  
  //T* find(const T& value) const { return find(root, value); }
  int getSize() const{ return getSize(head); }

  Node<T>* getHead(){return head;}
 private:


  Node<T>* head;
  Node<T>* tail;

  // Given
  void printList(const Node<T> *n, std::ostream &os) const;
  
  void insert(Node<T> *n, const T& v);
  int getSize(const Node<T> *n) const;
  Node<T>* find(const T& v);
  
};

#include "LinkedList.cpp"
#endif
