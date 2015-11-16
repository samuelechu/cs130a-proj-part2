#include "UserNetwork.h"
#include <iostream>
#include <sstream>
#include <string>
#include <limits>

void handleSelection(char a);
void createNewUser();
void loginUser();
void openUserMenu();
void handleUserSelection(char a);
void handleViewFriend();
void handleViewWall();
void handleUserSettings();
void handleSettingsSelection(char a);
void handleChangeUsername();
void handleChangePassword();
void handlePrintFriends();
void handleFriendSelection(char a, User* u);
void handleViewPost(User* u, int postNum);

User* currentUser;
string welcomeMessage = "Welcome to VisageLivre!\nSelect an option to begin:\n(1) Create New User\n(2) Login Existing User\n(0)Quit\n";
string userOptions = "Select an option to begin:\n(1) View A Friend's Wall\n(2) View Your Wall\n(3) User Settings\n(0)Logout\n";
UserNetwork* theNetwork = new UserNetwork();

int main(){
  theNetwork->loadUsers();
  theNetwork->printData();
  theNetwork->loadFriends();  
  bool loop = true;
  
    cout << welcomeMessage;
  
while (loop){

   string selection;
  
    cin >> selection;
    handleSelection(selection[0]);
    
    if(selection[0] == '0'){
      loop = false;
  	theNetwork->saveUsers();
  	theNetwork->saveFriends();
      return 0;
    }
    else if (selection[0] >= '3'){
      cout << "That is not a valid selection." << endl << endl;
    }
  }

  return 0;
}

void handleSelection(char a){
  
  if(a == '1'){
    createNewUser();
  }
  if(a == '2'){
   loginUser(); 
  }
}

void createNewUser(){
  
  string firstname;
  string lastname;
  string realName;
  string username;
  string password1;
  string password2;
  bool passMatch = false;
  string occupation;
   

  cout << "Enter your first name." << endl;
  cin >> firstname;

  cout << "Enter your last name." << endl;
  cin >> lastname;
  realName = firstname + ' ' + lastname; 
  
  cout << "Enter desired username." << endl;
  cin >> username;
  
  while(!passMatch){
    cout << "Create a  password." << endl;
    cin >> password1;
    cout << "Verify password." << endl;
    cin >> password2;
    if(password1.compare(password2) == 0)
      passMatch = true;
    else
      cout << "Passwords do not match!" << endl;
  }

  cout << "Enter current occupation." << endl;
  cin >> occupation;

  
  theNetwork->addUser(username, password1, realName, occupation);
  
  cout << "User successfully created!" << endl << endl;
  
    cout << welcomeMessage;
}

void loginUser(){
  string username;
  string password;
  bool invalid = true;

  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  while(invalid){
  cout << "Enter username." << endl;
  cin >> username;
  User *theUser = theNetwork->find(username);
  if(theUser == NULL){
    cout << "User does not exist!" << endl;
    invalid = true;
  }
  else{
    bool passCheck = false;
    invalid = false;
    
    while(!passCheck){
      cout << "Enter password for " << username << endl;
      cin >> password;
      if(password.compare(theUser->getPassword()) != 0){
        passCheck = false;
        cout << "Password incorrect!" << endl;
      }
      else{
        passCheck = true;
        currentUser = theUser;
		//currentUser->printWall();
        openUserMenu();
      }
    }
  }
 
  }

    cout << welcomeMessage;
}

void openUserMenu(){

  bool loop = true;

    cout << "Welcome to VisageLivre, " << currentUser->getRealName() << "!\n" << userOptions;

while (loop){

   string selection;

    cin >> selection;
    handleUserSelection(selection[0]);

    if(selection[0] == '0'){
      loop = false;
      return;
    }
    else if (selection[0] >= '4'){
      cout << "That is not a valid selection." << endl << endl;
    }
  }

  return;
}

void handleUserSelection(char selection){
  if(selection == '1')
    handleViewFriend();
  if(selection == '2')
    handleViewWall();
  if(selection == '3')
	handleUserSettings();
}
void handleViewFriend(){

      cout << "Who's wall would you like to view?"<< endl;

     string friendName;

      cin >> friendName;
	  User *theUser = theNetwork->find(friendName);
	  if(theUser == NULL){
	    cout << "User does not exist!" << endl;
	  }
	  else if(!currentUser->areFriends(friendName)){
		  cout << "You are not friends with " << friendName << ".\n";
	  }
	  else{
		  theUser->printWall();

			  string selection;
		  	  cout<<"What would you like to do?\n(1) View a post\n(2) Create new post\n(3) Delete a post\n(0) Return to previous menu"<<endl;
			  cin >> selection;
			  handleFriendSelection(selection[0], theUser);
	  }
     
    cout << "Welcome to VisageLivre, " << currentUser->getRealName() << "!\n" << userOptions;

    return;
}

void handleFriendSelection(char a, User* friends){
	if(a == '1'){
		cout<<"Which post would you like to view? (0-"<<(friends->getWallLength()-1)<<")\n";
		int postNum = 0;
		cin >> postNum;
		if(postNum < 0 || postNum >= friends->getWallLength())
			postNum = 0;
		handleViewPost(friends, postNum);	
	}	
	if(a == '2'){
		cout<<"Write your post!\n";
	  	string wallPost;
	  	cin.clear();
	  	cin.ignore();
	  	getline(cin, wallPost);
	  	cout << wallPost;
	  	friends->addWallPost(wallPost, "10:35AM", currentUser->getRealName());
	  	cin.clear();
	  	cout << "Post added successfully!"<< endl;
	}
		
}
void handleViewPost(User* user, int postNum){
	user->printPostWithResponses(postNum);
	cin.clear();
	cin.ignore();
	cout<<"What would you like to do?\n(1) Write Response\n(2) Delete Response\n(0) Return\n";
	string selection;
	cin >> selection;
	if(selection[0] == '0')
		return;
	if(selection[0] == '1'){
		cout<<"Write your response!\n";
		cin.clear();
		cin.ignore();
		string response;
    	getline(cin, response);
		user->addResponse(postNum, response, "10:48AM", currentUser->getRealName());
		cin.clear();
	}
	if(selection[0] == '2'){
		bool loop = true;
		while(loop){
			cout<<"Choose a response to delete. (0-"<<(user->getWallLength()-1)<<")\n";
			int choice=0;
			cin>>choice;
			WallPost* post = user->getPostByNum(choice);
			
		}
		
	}
}
void handleViewWall(){
	currentUser->printWall();
  cout << "Welcome to VisageLivre, " << currentUser->getRealName() << "!\n" << userOptions;
  
}

void handleUserSettings(){
    bool loop = true;

      cout << currentUser->getRealName() << "'s Settings:\nSelect an option to edit:\n(1) Change Username\n(2) Change Password\n(3) Print Friends\n(0) Return\n";

  while (loop){

     string selection;

      cin >> selection;
      handleSettingsSelection(selection[0]);

      if(selection[0] == '0'){
        loop = false;
        return;
      }
      else if (selection[0] >= '4'){
        cout << "That is not a valid selection." << endl << endl;
      }
    }

    return;
}

void handleSettingsSelection(char selection){
    if(selection == '1')
      handleChangeUsername();
    if(selection == '2')
	  handleChangePassword();
}

void handleChangeUsername(){
    bool invalid = true;

      cout << "Enter your password, for security purposes:"<< endl;

  while (invalid){

     string passwordTry;

      cin >> passwordTry;
      if(passwordTry.compare(currentUser->getPassword()) != 0){
        invalid = true;
        cout << "Password incorrect!" << endl;
      }
      else{
		  string newName;
        invalid = false;
		cout<<"Enter your desired username:"<<endl;
		cin>>newName;
		currentUser->setUsername(newName);
		cout<<"Username Successfully Changed! Congratulations, " + currentUser->getUsername() + "!"<<endl;
	}
	  
   
    
}
cout << currentUser->getRealName() << "'s Settings:\nSelect an option to edit:\n(1) Change Username\n(2) Change Password\n(3) Print Friends\n(0) Return\n";

return;
}

void handleChangePassword(){
    bool invalid = true;

      cout << "Enter your old password:"<< endl;

  while (invalid){

     string passwordTry;

      cin >> passwordTry;
      if(passwordTry.compare(currentUser->getPassword()) != 0){
        invalid = true;
        cout << "Password incorrect!" << endl;
      }
      else{
		  string newName;
        invalid = false;
		bool passMatch = false;
		string password1, password2;
		
	    while(!passMatch){
	      cout << "Enter desired password." << endl;
	      cin >> password1;
	      cout << "Verify password." << endl;
	      cin >> password2;
	      if(password1.compare(password2) == 0)
	        passMatch = true;
	      else
	        cout << "Passwords do not match!" << endl;
	    }
		currentUser->setPassword(password2);
		cout<<"Password Successfully Changed!"<<endl;
	}
}
}



