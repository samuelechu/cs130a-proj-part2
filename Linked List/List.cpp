#ifndef LIST_CPP__
#define LIST_CPP__
#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
void List<T>::insert(int pos, const T & item){
  if(pos < 0 || pos > size)
    return;

  List<T>::Node *newNode = new Node(item, NULL, NULL);

  if(pos == 0){ //insert at head or empty list
    
    if(head)
      head->prev = newNode;

    newNode->next = head;
    head = newNode;

      
  }

  
  else {
    List<T>::Node *n = getNode(pos - 1);
    if(n->next){
      n->next->prev = newNode;
    }
    
    
    newNode->next = n->next;
    newNode->prev = n;
    n->next = newNode;
    
  }
      

  size++;
}


template <typename T>
void List<T>::remove(int pos){


  if(pos < 0 || pos > size-1)
    return;
  
  List<T>::Node *n = getNode(pos);
  
  if(n){
    deleteNode(n);
    size--;
  }
}

template < typename T >
void List<T>::deleteNode(List<T>::Node *n){
  if(!n->next){
    n->prev->next = NULL;
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



template < typename T>
typename List<T>::Node* List<T>::getNode(int pos) const{

  List<T>::Node *n = head;

  int curPos = 0;
  while (n && curPos < pos ){

    n = n->next;
    curPos++;
  }

  return n;
}

template <typename T>
void List<T>::set(int pos, const T & item){
  
 if(pos < 0 || pos > size-1)
    return;

 List<T>::Node *n = getNode(pos);

  if(n){
    n->value = item;
  }
}

template <typename T>
T const & List<T>::get(int pos) const{
  
  /*if(pos < 0 || pos > size-1)
   return nullptr;*/

 List<T>::Node *n = getNode(pos);

 return n->value;
 

  // return nullptr;
}



////////////old functions

template < typename T >
void List<T>::deleteList(List<T>::Node *n){

  if(n == NULL)
    return;

  deleteList(n -> next);

  delete n;
  return;
}


template < typename T >
int List<T>::getSize(const List<T>::Node *n) const {
  
  if(!n)
    return 0;

  int result = getSize(n->next);

  return result + 1;
}

template < typename T >
void List<T>::printList() {
  
  List<T>::Node *n = head;

  while(n){
    cout<< n->value << endl;
    n = n->next;
  }

}



#endif
