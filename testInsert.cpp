#include "List.h"

#include <iostream>
#include "tddFuncs.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;

   List<int> l;
   
   cout << "Inserting 4 at pos 0" << endl;
   l.insert(0,4);


   cout << "Inserting 5 at pos 0" << endl;
   l.insert(0,5);

   cout << "Inserting 6 at pos 1" << endl;
   l.insert(1,6);

   cout << "Inserting 4 at pos 3" << endl;
   l.insert(2,4);
   

   cout << "\nCurrent List : \n";
   l.printList();
   ASSERT_EQUALS(4,l.getSize());

   cout << "\nDeleting Item at pos 2" << endl;
   l.remove(2);
   
   cout << "\nNew List after deleting position 2 \n";
   l.printList();


   ASSERT_EQUALS(3,l.getSize());

}
