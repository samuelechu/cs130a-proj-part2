#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include "UserNetwork.h"


using namespace std;

void UserNetwork::loadUsers(){
  ifstream myfile;
  myfile.open("network.txt");
  string input;
  string current;
  while(getline(myfile, current, '\n')){
    input += (current + "\n");
    cout<<input;
    if (myfile.peek() == '\n'){
    User newUser = User(input);
    
    users.insert(0,newUser);
    input = "";
    }
    
  }
  


  
}

  
void UserNetwork::addUser(User& user){

  List<User>::Node *n = users.getHead();

    while(n){

      if(n->value.getUsername().compare(user.getUsername()) == 0) 
	return;

      n = n->next;

    }

    users.insert(0,user);



}


void UserNetwork::addPost(string u, string post, string time){
    List<User>::Node *n = users.getHead();

      while(n){

        if(n->value.getUsername().compare(u) == 0){


            n->value.addWallPost(post, time);
            return;
        }
        n = n->next;

      }
}


void UserNetwork::printUsers(){


 List<User>::Node *n = users.getHead();

    while(n){
      cout<< n->value.getUsername() << "\n";
      n = n->next;
    }


}

void UserNetwork::printData(){
   List<User>::Node *n = users.getHead();

   while(n){
      cout<< n->value.getInfo() << "\n";
      n = n->next;
    }
  
}

void UserNetwork::saveUsers(){

 
 List<User>::Node *n = users.getHead();

 string s = "";
    while(n){
      s += n->value.getInfo();
      n = n->next;
    }


    ofstream out("UserNetwork.txt");
    out << s;
  
}

void UserNetwork::deleteUser(string u){
  
 List<User>::Node *n = users.getHead();
 int i = 0;
    while(n){
      
      if(n->value.getUsername().compare(u) == 0){
	users.remove(i);
	return;
      }

      i++;
      n = n->next;
    }


}
