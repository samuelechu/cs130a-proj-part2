#include "LinkedList.h"

#include <iostream>
#include "tddFuncs.h"
#include "UserNetwork.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;

   UserNetwork u;
   
   u.loadUsers();
   
   cout << "Current List: \n";
   u.printData();

   
   ASSERT_EQUALS(2,u.getSize());
   
   cout << "Deleting User: \"Sam\" \n";
   u.deleteUser("Sam");

   cout << "\nFinal List: \n";
   u.printData();
   


   ASSERT_EQUALS(1,u.getSize());

}
