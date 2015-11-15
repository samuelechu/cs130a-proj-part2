#ifndef __WALLPOST_H__
#define __WALLPOST_H__

#include <string>
#include <iostream>
#include "WallPostResponse.h"
using namespace std;

class WallPost{
 public:
 WallPost(string c, string t, string u) : contents(c),timePosted(t), username(u){}

  ~WallPost(){}
  string getContents(){return contents;}
  void setContents(string &s) { contents = s;}

  string getTimePosted(){return timePosted;}
  void setTimePosted(string &t){timePosted = t;}

  string getUsername(){return username;}
  void setUsername(string &u){username = u;}

  string getPost(){

    string post = username + "\n" + timePosted + "\n" + contents + getResponses()+ "\n";

    return post;


  }

  string getResponses(){

    string x = "";

    for (unsigned i = 0; i < responses.size(); i++){
      
      x+= responses[i].getResponse();
      x+= "\n";
    }
    return x;
    
  }
		     
  
  void printPost(){
	cout << "On " << timePosted << "\n" << username << " posted:" << "\n" << contents << endl;
  }
  
  
 private:
  string contents;
  string timePosted;
  string username;
  std::vector<WallPostResponse> responses;
};


#endif
