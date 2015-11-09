#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include "UserNetwork.h"


using namespace std;


void UserNetwork::saveUsers(){
 string s = "";
	for( unsigned i = 0; i <users.size(); ++i ){
		 s+= users[i].getSaveInfo();
	 }
 

    ofstream myFile;
	myFile.open("netwerk.txt");
    myFile << s;
	myFile.close();
}

void UserNetwork::loadUsers(){
  ifstream myfile;
  myfile.open("network.txt");
  string input;
  string current;
  while(getline(myfile, current, '\n')){
    input += (current + "\n");
    if (myfile.peek() == '\n'){
    	User * newUser = new User(input);
    	users.push_back(*newUser);
		getline(myfile,input,'\n');
    	input = "";
    }
    
  }
  myfile.close();
}
void UserNetwork::saveFriends(){
  ofstream myfile;
  myfile.open("friends.txt");
  for(int i=0;i<50;i++){
    for(int j=0;j<50;j++){
      myfile<<friendTable[i][j]<<" ";
    }
    myfile<<"\n";
  }
}
void UserNetwork::loadFriends(){
int input;
   ifstream file;
   file.open("friends.txt");
   int i=0;
   int j=0;
   if(file.is_open()){
      while(file.eof() == false){
        file>>input;
	friendTable[i][j] = input;
	j++;
	if(j >= 49){
	   j=0;
	   i++;
	}
      }
   }
file.close();

}
void UserNetwork::addFriends(int id1, int id2){
  friendTable[id1][id2] = 1;
  friendTable[id2][id1] = 1;
}
int UserNetwork::getNextID(){
  return users.size();
}
  
  
User* UserNetwork::find(string username){


	for( unsigned i = 0; i <users.size(); ++i ){
			if(users[i].getUsername().compare(username) == 0)
				return &users[i];
		}
return NULL;		


		
}  
User* UserNetwork::findByID(int ID){

	for( unsigned i = 0; i <users.size(); ++i ){
			if(users[i].getID() == ID)
				return &users[i];
		}
return NULL;		


		
}  
void UserNetwork::addUser(User& user){

	for( unsigned i = 0; i <users.size(); ++i ){
	        if(users[i].getUsername().compare(user.getUsername()) == 0) 
	  		  return;
		}
    users.push_back(user);
}

void UserNetwork::printFriends(int id){
	for(int i = 0; i<49; i++){
		if(friendTable[id][i] == 1){
			cout<<findByID(i)->getRealName()<<endl;
		}
	}
}

void UserNetwork::addPost(string writer, string u, string post, string t){
	for( unsigned i = 0; i <users.size(); ++i ){
		if(users[i].getUsername().compare(u) == 0){
			users[i].addWallPost(post, t, writer);
			return;
		}
	}
}


void UserNetwork::printUsers(){

	for( unsigned i = 0; i <users.size(); ++i ){
		cout << users[i].getUsername() << "\n";
	}
}

void UserNetwork::printData(){
	for( unsigned i = 0; i <users.size(); ++i ){
		cout << users[i].getInfo() << "\n";
	}
  
}



void UserNetwork::deleteUser(string u){
	for( unsigned i = 0; i <users.size(); ++i ){
		if(users[i].getUsername().compare(u) == 0){
			users.erase(users.begin()+i);
			return;
		}
	}
}
