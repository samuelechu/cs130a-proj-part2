#include <iostream>
#include <fstream>
#include "tddFuncs.h"
#include "UserNetwork.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;
   
   UserNetwork u;
   u.loadFriends();
    u.addFriends(1,3);
   u.addFriends(2,1);
   u.addFriends(4,5); 
   u.saveFriends();
   u.loadUsers();
   cout << "Current List: \n";
    u.printData();

   
   ASSERT_EQUALS(3,u.getSize());
   
   cout << "Deleting User: \"Sam\" \n";
   u.deleteUser("Sam");

   cout << "\nFinal List: \n";
   u.printData();
   


   ASSERT_EQUALS(2,u.getSize());

}
