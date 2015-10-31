#ifndef __LINKED_LIST_CPP__
#define __LINKED_LIST_CPP__
#include <iostream>
#include "LinkedList.h"
using namespace std;

template < typename T >
void LinkedList<T>::printList(const LinkedList<T>::Node *n, std::ostream &os) const {
  if(!n)
    return;
  else {
    os << n->value << endl;
    
    if(n->next)
      printList(n->next, os);
 

  }
}

template <typename T>
void LinkedList<T>::deleteAtNdx(int index){

  Node *n = head;

  int curNdx = 0;
  while (n || curNdx < index){

    n = n->next;
    curNdx++;
  }


  if(n)
    deleteNode(n);
}


template < typename T>
typename LinkedList<T>::Node* LinkedList<T>::find(const T& v){
  Node *n = head;
  Node *found = NULL;
  
  while(n){
    if(n->value == v){
      found = n;
      return found;
    }

    n = n->next;

  }

  return found;


}

template < typename T >
void LinkedList<T>::deleteNode(LinkedList<T>::Node *n){
  if(!n->next){
    n->prev->next = NULL;
    tail = n->prev;
    delete n;
  }
  else if(!n->prev){
    n->next->prev = NULL;
    head = n->next;
    delete n;
    return;
  }
  else{
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
  }
    
  
}

template < typename T >
void LinkedList<T>::deleteList(LinkedList<T>::Node *n){

  if(n == NULL)
    return;

  deleteList(n -> next);

  delete n;
  return;
}


template < typename T >
int LinkedList<T>::getSize(const LinkedList<T>::Node *n) const {
  
  if(!n)
    return 0;

  int result = getSize(n->next);

  return result + 1;
}


template < typename T >
void LinkedList<T>::insert(LinkedList<T>::Node *n, const T &c) {

  
  LinkedList<T>::Node *newNode = new Node(c, NULL, NULL);

  newNode -> prev = n;
  n -> next = newNode;
  tail = newNode;
  return;
}

#endif
