#include <iostream>
#include <fstream>
#include "tddFuncs.h"
#include "UserNetwork.h"
#include "User.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;
   
   UserNetwork* u = new UserNetwork();
   User* curUser;

   u->loadUsers();

   
   u->loadFriends();

   curUser = u->find("Sam");
   u->addFriend(curUser, "Gumpy");
   u->addFriend(curUser, "Sizor");
   u->addFriend(curUser, "Andrew");

   
   u->printFriends(curUser);
   ASSERT_EQUALS(true, u->areFriends(curUser, "Gumpy"));
   
 
   u->findAllAtDepth(curUser, 1); 
   
   ASSERT_EQUALS(3,u->getSize());
   
   cout << "Deleting User: \"Gumpy\" \n";
   u->deleteUser("Gumpy");

   u->printFriends(curUser);
   ASSERT_EQUALS(false, u->areFriends(curUser, "Gumpy"));

   
   string username;
   string realName;
   string password;
   string occupation;

   for(int k = 0; k<10000; k++){
     curUser = u->find("Bob" + std::to_string(k));
     for(int j = 0; j<100; j++){
       int random = rand() * 10000;
       u->addFriend(curUser, "Bob" + std::to_string(random));
     }
   }
   

   ASSERT_EQUALS(2,u->getSize());
   u->saveFriends();
   u->saveUsers();
   u->printTest();
   
   
}
