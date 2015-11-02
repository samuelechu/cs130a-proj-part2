#include "List.h"

#include <iostream>
#include "tddFuncs.h"
#include "UserNetwork.h"

using namespace std;

int main(){

   cout << "Running tests from: " << __FILE__ << endl;

   UserNetwork u;
   

   u.addUser("Sam", "pass123", "Samuel Chu", "software developer");
   u.addUser("Sam", "pass123", "Samuel Chu", "software developer");
   u.addUser("Andrew", "pas123", "Andrew Myers", "software developer");
   u.addPost("Sam","Sam","Hello Humpty Dumpty!!", "7:30 PM");
   u.addPost("Sam","Andrew","Hi there bubby!", "9:99 AM");
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
