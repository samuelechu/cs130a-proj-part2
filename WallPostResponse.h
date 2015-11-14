 
#ifndef __WALLPOSTRESPONSE_H__
#define __WALLPOSTRESPONSE_H__

#include <string>
#include <iostream>
using namespace std;

class WallPostResponse{

 public:
 WallPostResponse(string c, string t, string u):contents(c),timePosted(t), username(u){}


  ~WallPostResponse(){}

  string getResponse(){

    return username + "\n" + timePosted + "\n" + contents + "\n\n";
  }



 private:

  string contents;
  string timePosted;
  string username;

};


#endif
