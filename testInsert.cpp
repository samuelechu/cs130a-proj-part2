#include "List.h"

#include <iostream>
#include "tddFuncs.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;

   List<int> l;


   ///inserts
   cout << "Inserting 4 at pos 0" << endl;
   l.insert(0,4);


   cout << "Inserting 5 at pos 0" << endl;
   l.insert(0,5);

   cout << "Inserting 6 at pos 1" << endl;
   l.insert(1,6);

   cout << "Inserting 4 at pos 3" << endl;
   l.insert(2,4);
   


   //printlist
   cout << "\nCurrent List : \n";
   l.printList();
   ASSERT_EQUALS(4,l.getSize());




   //delete
   cout << "\nDeleting Item at pos 2" << endl;
   l.remove(2);
   
   cout << "\nNew List after deleting position 2 \n";
   l.printList();


   ASSERT_EQUALS(3,l.getSize());





   ///set
   cout << "\nSetting element at position 0 to 10 \n";
   l.set(0, 10);

   //get
   cout << "\nCurrent List : \n";
   l.printList();
   
   ASSERT_EQUALS(4,l.get(2));
   ASSERT_EQUALS(10,l.get(0));
   ASSERT_EQUALS(3,l.getSize());

   

   
}
