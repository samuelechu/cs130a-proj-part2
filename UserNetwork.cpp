#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "UserNetwork.h"


using namespace std;


void UserNetwork::saveUsers(){
 string s = "";
	for( unsigned i = 0; i <users.size(); ++i ){
		 s+= users[i]->getSaveInfo();
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
    	users.push_back(newUser);
		getline(myfile,input,'\n');
    	input = "";
    }
    
  }
  myfile.close();
}
void UserNetwork::saveFriends(){
  ofstream myfile;
  myfile.open("friends.txt");


  
  for(unsigned i=0;i<users.size();i++){
    string friends = users[i]->getFriends();

      myfile << friends << "\n";
    }
}

void UserNetwork::loadFriends(){

int curLine = 0;
User* curUser;
   ifstream file;
   file.open("friends.txt");
   
   string line;


   
   if(file.is_open()){
     while (getline(file, line)){
     	curUser = findByID(curLine);
     	
	 stringstream s(line);
	 string input;

	 while (s >> input){
	 	User* friend = findByID(stoi(input));
	   curUser->addFriend(friend);
	  
	 }
	 curLine++;
       }


     
   }
file.close();


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
	  if(users[i]->getUsername().compare(username) == 0 || users[i]->getRealName().compare(username) == 0)
				return users[i];
		}
return NULL;		


		
}  
User* UserNetwork::findByID(int ID){

	for( unsigned i = 0; i <users.size(); ++i ){
			if(users[i]->getID() == ID)
				return users[i];
		}
return NULL;		


		
}  
void UserNetwork::addUser(User* user){

	for( unsigned i = 0; i <users.size(); ++i ){
	        if(users[i]->getUsername().compare(user->getUsername()) == 0) 
	  		  return;
		}
    users.push_back(user);
}

/*void UserNetwork::printFriends(int id){
	for(int i = 0; i<49; i++){
		if(friendTable[id][i] == 1){
			cout<<findByID(i)->getRealName()<<endl;
		}
	}
}*/

void UserNetwork::addPost(User* writer, string u, string post, string t){


  User *recipient = find(u);
  if(recipient)
    if(writer->areFriends(u))
       recipient->addWallPost(post,t, writer->getRealName());
}


bool UserNetwork::areFriends(User* user1, string username){

  return user1->areFriends(username);

}


void UserNetwork::printUsers(){

	for( unsigned i = 0; i <users.size(); ++i ){
		cout << users[i]->getUsername() << "\n";
	}
}

void UserNetwork::printData(){
	for( unsigned i = 0; i <users.size(); ++i ){
		cout << users[i]->getInfo() << "\n";
	}
  
}



void UserNetwork::deleteUser(string u){
	for( unsigned i = 0; i <users.size(); ++i ){
		if(users[i]->getUsername().compare(u) == 0){
			users.erase(users.begin()+i);
			return;
		}
	}
}


void UserNetwork::shortestPath(User* source, string username){
	
for( unsigned i = 0; i <users.size(); ++i ){
	        if(users[i]->getUsername().compare(user->getUsername()) == 0) 
	  		  User* destination = BreadthFirstSearch(source, username);
	  		  cout<< "Depth: " << destination->getDistance()<< "\nPath:\n";
	  		  
	  		  
	  		  vector<User *> path;
	  		  while (destination){
	  		  	path.push(destination);
	  		  	destination = destination->getParent();
	  		  }
	  		  
	  		  for(unsigned i = path.size() - 1; i >= 0; i--){
	  		  	cout << path[i]->getRealName() << " -> ";
	  		  }
	  		  
	  		  return;
		}	
	
}



User* UserNetwork::BreadthFirstSearch(User *source, string username){
	
	User* curUser;
	
	for(unsigned i = 0; i < users.size(); i++){
		users[i]->resetDistance();
	}
	
	queue<User*> q;
	
	source->setDistance(0);
	q.push(source);
	
	
	while (!q.empty()){
		
		curUser = q.front();
		q.pop();
		
		vector<User*> adjacentNodes = curUser->getAdjacent();
		
		for(unsigned i = 0; i < adjacentNodes.size(); i++){
			User * child = adjacentNodes[i];
			
			if (child->getDistance() == -1){
				child->setDistance(curUser->getDistance() + 1));
				child->setParent(curUser);
				
				if(child->getUsername().compare(username) == 0)
					return child;
				
				
				q.push(child);
			}
			
			
			
			
		}
		
		
	}
	
	return curUser;
	
	
}







