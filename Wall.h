#ifndef __WALL_H__
#define __WALL_H__

#include <string>
#include <iostream>
#include <vector>
#include "WallPost.h"
using namespace std;

class Wall{
 public:

  Wall(){
 
 }


 Wall(string u): username(u){

  }

  ~Wall(){


  }

  //  void loadPosts(string posts);
  void insert(string c, string t, string u);
  void insert(WallPost* post){wallPosts.push_back(*post);}
  void remove(int index);
  
  void addResponse(int num, string c, string t, string u){wallPosts[num].addResponse(c,t,u);}
  
  int getSize(){return wallPosts.size();}

  string getWall();
  void printWall();
  void printPost(int i){wallPosts[i].printPost(i);}
  void printPostWithResponses(int i){wallPosts[i].printPostWithResponses();}
  
  WallPost* getPostByNum(int num){return &wallPosts[num];}
  
  string getUsername(){return username;}
  void setUsername(string &u){username = u;}

  
 private:

  std::vector<WallPost> wallPosts;
  string username;

};
#endif
