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
   string line;


   
   if(file.is_open()){
     /* while (getline(file, line){
	 stringstream s(line);
	 string input;

	 while (s >> input){
	   friendTable[i][j] = input;
	   j++;
	 }

	 i++;
       }*/


     
     while(file.eof() == false){
        file>>input;
	if(input == '\n')
	friendTable[i][j] = input;
	j++;
	if(j >= 50){
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

void UserNetwork::addFriend(User *user1, string username){
  User *user2 = find(username);
  user1->addFriend(user2);
  

}


int UserNetwork::getNextID(){
  return users.size();
}
  
  
User* UserNetwork::find(string username){


	for( unsigned i = 0; i <users.size(); ++i ){
	  if(users[i].getUsername().compare(username) == 0 || users[i].getRealName().compare(username) == 0))
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

void UserNetwork::addPost(User writer, string u, string post, string t){


  User *recipient = find(u);
  if(recipient)
    if(areFriends(writer.getID(), recipient->getID())
	recipient->addWallPost(post,t, writer.getRealName();
}


bool UserNetwork::areFriends(int writer, int u){

  return friendTable[writer][u] == 1;

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
