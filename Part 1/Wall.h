#ifndef __WALL_H__
#define __WALL_H__

#include <string>
#include <iostream>
#include "WallPost.h"
#include "List.h"
using namespace std;

class Wall{
 public:

  Wall(){
 
 }


 Wall(string u): username(u){

  }

  ~Wall(){


  }

  void loadPosts(string posts);
  void insert(string c, string t, string u);
  void remove(int index);

  string getWall();
  void printWall();
  
  string getUsername(){return username;}
  void setUsername(string &u){username = u;}

  
 private:

  LinkedList<WallPost> wallPosts;
  string username;

};
#endif
