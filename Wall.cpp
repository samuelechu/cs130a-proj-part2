#include <string>
#include <iostream>
#include <vector>
#include "Wall.h"

using namespace std;

void Wall::insert(string c, string t, string u){
	
  WallPost* w = new WallPost(c, t, u);
  wallPosts.push_back(*w);
}

/*void Wall::loadPosts(string posts){
List<WallPost>::Node *head = wallPosts.getHead();

 wallPosts.deleteList(head);
  
  

  
 }*/

void Wall::remove(int index){


  wallPosts.erase(wallPosts.begin() + index);
  

}

string Wall::getWall(){

  string out = "";
  std::vector<WallPost>::iterator it;

  for(it = wallPosts.begin(); it != wallPosts.end(); it++){
    int i = std::distance( wallPosts.begin(), it );
    out += wallPosts[i].getPost();
  }

  return out;

}

void Wall::printWall(){



  std::vector<WallPost>::iterator it;

  for(it = wallPosts.begin(); it != wallPosts.end(); it++){
    int i = std::distance( wallPosts.begin(), it );
    wallPosts[i].printPost();
  }

 
}
