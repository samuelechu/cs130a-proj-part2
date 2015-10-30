#ifndef LIST_CPP__
#define LIST_CPP__
#include <iostream>
#include "List.h"
using namespace std;

template <typename T>
void List<T>::insert(int pos, const T & item){
  if(pos < 0 || pos > size)
    return;

  if(pos == arrSize || size == arrSize){//double array size
    T * newArr = new T[arrSize*2];
    for(int i =  0; i < size; i++)
      newArr[i] = arr[i];
    delete[] arr;
    arr = newArr;
    arrSize *= 2;
    insert(pos, item);
  }

  else{
    for(int i = size; i > pos; i--)
      arr[i] = arr[i-1];
    arr[pos] = item;
    size++;
    
  }
  
}

template <typename T>
void List<T>::remove(int pos){
  if(pos < 0 || pos > size-1)
    return;

  for(int i = pos; i < size - 1; i++)
    arr[i] = arr[i+1];

  
  size--;


  
}


template <typename T>
void List<T>::set(int pos, const T & item){
   if(pos < 0 || pos > size-1)
    return;

   arr[pos] = item;
   
   
}

template <typename T>
T const & List<T>::get(int pos) const{

  
  return arr[pos];
}



////////////old functions



#endif

