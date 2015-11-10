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
    User newUser = User(u,  p, rn, occ, getNextID());
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
  void addPost(string writer, string u, string post, string time);
  int getNextID();
  User* find(string username);
  User* findByID(int id);
  void printFriends(int id);
  
  
  void addFriends(int id1, int id2);
  int getSize(){return users.size();}

 private:
  std::vector<User> users;
  
  int friendTable[51][51] = {{0}};

  void addUser(User& user);
};

#endif
