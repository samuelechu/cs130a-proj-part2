#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <iostream>
#include <sstream>
#include "Wall.h"
using namespace std;

class User{
 public:
  /*User(Wall w, string p, string rn, string occ): password(p), realName(rn), occupation(occ){
    username = w.getUsername();
  }*/


 User(string u, string p, string rn, string occ): username(u),  password(p), realName(rn), occupation(occ){
    wall.setUsername(u);
  }

 User(string u, string p, string rn, string occ, string wall): username(u),  password(p), realName(rn), occupation(occ){
    // wall.setUsername(u);
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
 
  
  string getUsername(){return username;}
  void setUsername(string &u){username = u;}
  
  string getPassword(){return password;}
  void setPassword(string &p){password = p;}

  string getRealName(){return realName;}
  void setRealName(string &rn){realName = rn;}

  string getOccupation(){return occupation;}
  void setOccupation(string &occ){occupation = occ;}

  void addWallPost(string c, string t){wall.insert(c, t, username);}
  void deleteWallPost(int index) { wall.remove(index);};
 private:

  Wall wall;
  string username;
  string password;
  string realName;
  string occupation;

};
#endif
