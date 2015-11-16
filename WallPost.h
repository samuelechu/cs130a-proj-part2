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

    string post = username + "\n" + timePosted + "\n" + contents +"\n"+ getResponses();

    return post;


  }
  void addResponse(WallPostResponse* response){
	  responses.push_back(*response);
  }
  void addResponse(string c, string t, string u){
	  WallPostResponse* response = new WallPostResponse(c,t,u);
	  responses.push_back(*response);
  }

  string getResponses(){

    string x = "";

    for (unsigned i = 0; i < responses.size(); i++){
		x+= "\t";
      x+= responses[i].getResponse();
    }
    return x;
    
  }
		     
  
  void printPost(int i){
	  string responseNum = " people have responded to this post.";
	  if(responses.size() == 1)
		  responseNum = " person has responded to this post.";
	cout <<"["<<i<<"]\n"<< "On " << timePosted << "\n" << username << " posted:" << "\n" << contents << endl << responses.size() << responseNum << endl;
  }
  void printPostWithResponses(){
  	cout << "On " << timePosted << "\n" << username << " posted:" << "\n" << contents << endl;
	for(unsigned j = 0; j<responses.size(); j++){
		cout<<"["<<j<<"]\n";
		responses[j].printResponse();
	}
  
  }
  
  
 private:
  string contents;
  string timePosted;
  string username;
  std::vector<WallPostResponse> responses;
};


#endif
