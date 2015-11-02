#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include "UserNetwork.h"


using namespace std;


void UserNetwork::saveUsers(){


 List<User>::Node *n = users.getHead();
 string s = "";
    while(n){
      s += n->value.getSaveInfo();
	  cout<<"nope"<<endl;
      n = n->next;
    }

    ofstream myFile;
	myFile.open("netwerk.txt");
    myFile << s;
	myFile.close();
  
}

void UserNetwork::loadUsers(){
	cout<<"Got hear";
  ifstream myfile;
  myfile.open("network.txt");
  string input;
  string current;
  while(getline(myfile, current, '\n')){
    input += (current + "\n");
    if (myfile.peek() == '\n'){
     User * newUser = new User(input);
	 cout<< newUser->getSaveInfo();
    users.insert(users.getSize(), *newUser);
	//cout << users.getHead()->value.getSaveInfo();
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
  return users.getSize();
}
  
  
List<User>::Node * UserNetwork::find(string username){

	List<User>::Node* n = users.getHead();
	while(n){
		if(n->value.getUsername().compare(username) == 0){
			return n;
		}
		n = n->next;
	}
return NULL;		


		
}  
List<User>::Node * UserNetwork::findByID(int ID){

	List<User>::Node* n = users.getHead();
	while(n){
		if(n->value.getID() == ID){
			return n;
		}
		n = n->next;
	}
return NULL;		


		
}  
void UserNetwork::addUser(User& user){

  List<User>::Node *n = users.getHead();

    while(n){

      if(n->value.getUsername().compare(user.getUsername()) == 0) 
	return;

      n = n->next;

    }

    users.insert(users.getSize(),user);



}


void UserNetwork::addPost(string writer, string u, string post, string time){
    List<User>::Node *n = users.getHead();

      while(n){

        if(n->value.getUsername().compare(u) == 0){


            n->value.addWallPost(post, time, writer);
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



void UserNetwork::deleteUser(string u){
  
 List<User>::Node *n = users.getHead();
  int i = 0;
    while(n){
      
  cout<<users.getSize()<<endl;
      if(n->value.getUsername().compare(u) == 0){
      users.remove(i);
	return;
      }
      i++;
      n = n->next;
    }


}
