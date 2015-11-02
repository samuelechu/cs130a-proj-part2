#ifndef __USER_NETWORK_H__
#define __USER_NETWORK_H__

#include <string>
#include <iostream>
#include <fstream>
#include "User.h"
#include "Wall.h"
#include "List.h"

using namespace std;

class UserNetwork{

 public:
  UserNetwork(){
  }

  void addUser(string u, string p, string rn, string occ){
    User newUser = User(u,  p, rn, occ, getNextID());
    addUser(newUser);
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
  List<User>::Node* find(string username);
  List<User>::Node* findByID(int id);
  string getFriends(int id)
  
  
  void addFriends(int id1, int id2);
  int getSize(){return users.getSize();}

 private:
  List<User> users;
  
  int friendTable[50][50] = {{0}};

  void addUser(User& user);
};

#endif
