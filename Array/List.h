#ifndef __LIST_H__
#define __LIST_H__

#include <iostream>

template < typename T >
class List {
 public:
  int curPos;
  // Default constructor
 List(): size(0), arrSize(1) {curPos = 0;  arr = new T[1]; }

  ~List() { delete[] arr; }

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

 void printList(){
   for(int i = 0; i < size; i++)
     std::cout<< arr[i] << std::endl;
 }
 
int getSize(){ return size; }

private:
  T * arr;
  int size;
  int arrSize;



};
#include "List.cpp"
#endif

