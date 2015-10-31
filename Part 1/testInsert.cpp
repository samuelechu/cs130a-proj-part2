#include "LinkedList.h"

#include <iostream>
#include "tddFuncs.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;

   LinkedList<int> l;
   

   l.insert(4);
   l.insert(5);
   l.insert(6);
   l.insert(4);
   
   cout << "Current List : \n" << l;


   l.deleteValue(5);
   
   cout << "New List after deleting value 5: \n" << l;


   ASSERT_EQUALS(3,l.getSize());

}
