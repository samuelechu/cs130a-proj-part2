#include <string>
#include <iostream>
#include "Wall.h"

using namespace std;

void Wall::insert(string c, string t, string u){
  WallPost w = WallPost(c, t, u);

  wallPosts.insert(0,w);

}

void Wall::loadPosts(string posts){
List<WallPost>::Node *head = wallPosts.getHead();

 wallPosts.deleteList(head);
  
  

  
}

void Wall::remove(int index){


  wallPosts.remove(index);
  

}

string Wall::getWall(){
  List<WallPost>::Node *n = wallPosts.getHead();

  string out = "";
  
  while(n){
    out += n->value.getPost();
    n = n->next;
  }

  return out;

}

void Wall::printWall(){

  List<WallPost>::Node *n = wallPosts.getHead();
  
  while(n){
    n->value.printPost();
    n = n->next;
  }
}
