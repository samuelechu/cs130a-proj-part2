#include <iostream>
#include <fstream>
#include "tddFuncs.h"
#include "UserNetwork.h"
#include "User.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;
   
   UserNetwork u;
   User* curUser;

   u.loadUsers();

   
   u.loadFriends();

   curUser = u.find("Sam");
   u.addFriend(curUser, "Gumpy");
   u.addFriend(curUser, "Sizor");
   u.addFriend(curUser, "Andrew");

   
   u.printFriends(curUser);
   ASSERT_EQUALS(true, u.areFriends(curUser, "Gumpy"));
   
 
    
   
   ASSERT_EQUALS(3,u.getSize());
   
   cout << "Deleting User: \"Gumpy\" \n";
   u.deleteUser("Gumpy");

   u.printFriends(curUser);
   ASSERT_EQUALS(false, u.areFriends(curUser, "Gumpy"));

   
   


   ASSERT_EQUALS(2,u.getSize());
   u.saveFriends();

}
