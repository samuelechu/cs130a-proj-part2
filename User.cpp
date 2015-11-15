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

vector<int> User::getFriends(){
  vector<int> friendList;

  for(unsigned i = 0; i < friends.size(); i++){
	  friendList.push_back(friends[i]->getID());
	
    
}
return friendList;


}

void User::deleteFriend(string u){
  for(unsigned i = 0; i < friends.size(); i++){
    if(friends[i]->getUsername().compare(u) == 0){
       friends.erase(friends.begin() + i);
       return;
    }

  }
  
}
