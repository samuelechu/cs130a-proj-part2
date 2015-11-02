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

int UserNetwork::getNextID(){
  LinkedList<User>::Node * n = users.getHead();
  if(!n)
    return 0;
  while(n->next){
    n = n->next;
  }
  return n->value.getID() + 1;
}
  
void UserNetwork::addUser(User& user){

  LinkedList<User>::Node *n = users.getHead();

    while(n){

      if(n->value.getUsername().compare(user.getUsername()) == 0) 
	return;

      n = n->next;

    }

    users.insert(user);



}


void UserNetwork::addPost(string u, string post, string time){
    LinkedList<User>::Node *n = users.getHead();

      while(n){

        if(n->value.getUsername().compare(u) == 0){


            n->value.addWallPost(post, time);
            return;
        }
        n = n->next;

      }
}


void UserNetwork::printUsers(){


 LinkedList<User>::Node *n = users.getHead();

    while(n){
      cout<< n->value.getUsername() << "\n";
      n = n->next;
    }


}

void UserNetwork::printData(){
   LinkedList<User>::Node *n = users.getHead();

   while(n){
      cout<< n->value.getInfo() << "\n";
      n = n->next;
    }
  
}

void UserNetwork::saveUsers(){

 
 LinkedList<User>::Node *n = users.getHead();

 string s = "";
    while(n){
      s += n->value.getInfo();
      n = n->next;
    }


    ofstream out("UserNetwork.txt");
    out << s;
  
}

void UserNetwork::deleteUser(string u){
  
 LinkedList<User>::Node *n = users.getHead();

    while(n){
      
      if(n->value.getUsername().compare(u) == 0){
	users.deleteNode(n);
	return;
      }
	
      n = n->next;
    }


}
