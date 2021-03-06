#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "Wall.h"
using namespace std;

class User{
 public:
    
	 User(){}
 User(string u, string p, string rn, string occ, int id): username(u),  password(p), realName(rn), occupation(occ), userID(id){
    wall.setUsername(u);
    parent = NULL;
    distance = -1;
 
  }

 User(string u, string p, string rn, string occ, string wall, int id): username(u),  password(p), realName(rn), occupation(occ), userID(id){
  parent = NULL;
    distance = -1;
  }

  User(string input){
   /* stringstream iss(input);
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
    this->userID = atoi(word.c_str());

    string date;
    string user;    

    while(getline(iss, word, '\n')){
      user = word;
      getline(iss, word, '\n');
      date = word;
      getline(iss, word, '\n');
	  while(peek())
      addWallPost(word, date, user);
    }
	  */
  }


  
  ~User(){


  }

void resetDistance(){
	
	parent = NULL;
	distance = -1;
}

User* getParent(){return parent;}
int getDistance(){return distance;}

void setParent(User* user){
	parent = user;
}

void setDistance(int distance){
	this->distance = distance;
}


  string getInfo(){
    return "Username: " + username + "\nPassword: " + password + "\nFull Name:" + realName + "\nOccupation: " + occupation + "\nWall Posts:\n" + wall.getWall();
  }
  string getSaveInfo(){
    return username + "\n" + password + "\n" + realName +"\n" + occupation + "\n" + to_string(userID) + "\n" + wall.getWall() + "\n";
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
  
  int getWallLength(){return wall.getSize();}

  void addWallPost(string c, string t, string u){wall.insert(c, t, u);}
  void addWallPost(WallPost* post){wall.insert(post);}
  void addResponse(int num, string c, string t, string u){wall.addResponse(num, c, t, u);}
  void deleteWallPost(int index) { wall.remove(index);};
  
  void printWall(){wall.printWall();};
  void printPost(int i){wall.printPost(i);}
  void printPostWithResponses(int i){wall.printPostWithResponses(i);}
  
  WallPost* getPostByNum(int num){return wall.getPostByNum(num);}

  void addFriend(User* friendz){
    friends.push_back(friendz);
  }

  bool areFriends(string username);
  std::vector<int> getFriends();
  void deleteFriend(string username);
  
std::vector<User*> getAdjacent(){return friends;}
  
 private:

  std::vector<User *> friends;
  Wall wall;
  string username;
  string password;
  string realName;
  string occupation;
  int userID;
  
//Breadth First Search 
  User* parent;
  int distance;

};
#endif
