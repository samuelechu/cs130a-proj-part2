#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <iostream>
#include <sstream>
#include "Wall.h"
using namespace std;

class User{
 public:
    


 User(string u, string p, string rn, string occ, int id): username(u),  password(p), realName(rn), occupation(occ), userID(id){
    wall.setUsername(u);
    //loadFriends(); 
  }

 User(string u, string p, string rn, string occ, string wall, int id): username(u),  password(p), realName(rn), occupation(occ), userID(id){
    // wall.setUsername(u);
    //loadFriends();
  }

  User(string input){
    stringstream iss(input);

    string word;
    getline(iss, word, '\n');
    this->username  = word;
    getline(iss, word, '\n');
    this->password = word;
    getline(iss, word,'\n');
    this->realName = word;
    getline(iss, word, '\n');
    this->occupation = word;
    getline(iss, word, '\n');
    this->userID = stoi(word);

    string date;
    
    while(getline(iss, word, '\n')){
      date = word;
      getline(iss, word, '\n');
      addWallPost(word, date);
    }
  }


  
  ~User(){


  }

  string getInfo(){
    return "Username: " + username + "\nPassword: " + password + "\nFull Name:" + realName + "\nOccupation: " + occupation + "\nWall Posts:\n" + wall.getWall();
  }
  
  //void loadFriends();

  string getUsername(){return username;}
  void setUsername(string &u){username = u;}
  
  string getPassword(){return password;}
  void setPassword(string &p){password = p;}

  string getRealName(){return realName;}
  void setRealName(string &rn){realName = rn;}

  string getOccupation(){return occupation;}
  void setOccupation(string &occ){occupation = occ;}

  int getID(){return userID;}
  void setID(int id){userID = id;}

  void addWallPost(string c, string t){wall.insert(c, t, username);}
  void deleteWallPost(int index) { wall.remove(index);};
 private:

  LinkedList<User> friends;
  Wall wall;
  string username;
  string password;
  string realName;
  string occupation;
  int userID;
};
#endif
