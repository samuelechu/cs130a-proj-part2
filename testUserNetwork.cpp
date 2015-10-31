#include "List.h"

#include <iostream>
#include "tddFuncs.h"
#include "UserNetwork.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;

   UserNetwork u;
   

   u.addUser("Sam", "Sammy", "Samuel Chu", "software developer");
   u.addUser("Sam", "Sammy", "Samuel Chu", "software developer");
   u.addUser("Andrew", "Myers", "Andrew Myers", "software developer");
   u.addPost("Sam","Hello World!", "7:30 PM");
   cout << "Current List: \n";
   u.printUsers();
   u.saveUsers();
   
   ASSERT_EQUALS(2,u.getSize());
   
   cout << "Deleting User: \"Sam\" \n";
   u.deleteUser("Sam");

   cout << "\nFinal List: \n";
   u.printUsers();
   


   ASSERT_EQUALS(1,u.getSize());

}
