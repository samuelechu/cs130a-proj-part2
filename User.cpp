#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "User.h"
#include "UserNetwork.h"
using namespace std;


bool User::areFriends(string username){

  for(unsigned i = 0; i < friends.size(); i++){
     if(friends[i]->getUsername().compare(username) == 0) 
	  		  return true;
		}

  
return false;


}

string User::getFriends(){
  string friendList = "";

  for(unsigned i = 0; i < friends.size(); i++){
    friendList += friends[i].getID();

    friendList += " ";
    
}
return friendList;



}
