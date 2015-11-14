#ifndef __USER_NETWORK_H__
#define __USER_NETWORK_H__

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "User.h"
#include "Wall.h"

using namespace std;

class UserNetwork{

 public:
  UserNetwork(){
  }

  void addUser(string u, string p, string rn, string occ){
    User* newUser = new User(u,  p, rn, occ, getNextID());
    addUser(newUser);
  }
   
 ~UserNetwork(){

   
  }

  
  void deleteUser(string u);
  void printData();
  void printUsers();
  void loadUsers();
  void saveUsers();
  void loadFriends();
  void saveFriends();
  void addPost(User* writer, string u, string post, string time);
  int getNextID();
  User* find(string username);
  User* findByID(int id);
  void printFriends(int id);
  bool areFriends(User* user1, string username);
  
  
  void addFriend(User* user1, string username);
  
  int getSize(){return users.size();}

 private:
  std::vector<User *> users;
  

  void addUser(User* user);
};

#endif
