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
void handleCreatePost();
void handleDeletePost();
void handlePrintWall();
void handleUserSettings();
void handleSettingsSelection(char a);
void handleChangeUsername();
void handleChangePassword();
void handlePrintFriends();

User* currentUser ;
UserNetwork theNetwork;
int main(){
  theNetwork.loadUsers(); 
  //theNetwork.loadFriends();  
  bool loop = true;
  
    cout << "Welcome to VisageLivre!\nSelect an option to begin:\n(1) Create New User\n(2) Login Existing User\n(0)Quit\n";
  
while (loop){

   string selection;
  
    cin >> selection;
    handleSelection(selection[0]);
    
    if(selection[0] == '0'){
      loop = false;
  	theNetwork.saveUsers();
  	//theNetwork.saveFriends();
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

  
  theNetwork.addUser(username, password1, realName, occupation);
  
  cout << "User successfully created!" << endl << endl;
  
    cout << "Welcome to VisageLivre!\nSelect an option to begin:\n(1) Create New User\n(2) Login Existing User\n(0)Quit\n";
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
  User *theUser = theNetwork.find(username);
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
		currentUser->printWall();
        openUserMenu();
      }
    }
  }
 
  }

    cout << "Welcome to VisageLivre!\nSelect an option to begin:\n(1) Create New User\n(2) Login Existing User\n(0)Quit\n";
}

void openUserMenu(){

  bool loop = true;

    cout << "Welcome to VisageLivre, " << currentUser->getRealName() << "!\nSelect an option to begin:\n(1) Create Wall Post\n(2) Delete a Wall Post\n(3) Print Wall\n(4) User Settings\n(0)Logout\n";

while (loop){

   string selection;

    cin >> selection;
    handleUserSelection(selection[0]);

    if(selection[0] == '0'){
      loop = false;
      return;
    }
    else if (selection[0] >= '5'){
      cout << "That is not a valid selection." << endl << endl;
    }
  }

  return;
}

void handleUserSelection(char selection){
  if(selection == '1')
    handleCreatePost();
  if(selection == '2')
    handleDeletePost();
  if(selection == '3')
    handlePrintWall();
  if(selection == '4')
	  handleUserSettings();
}
void handleCreatePost(){
    bool invalid = true;

      cout << "Who's wall would you like to post on?"<< endl;

  while (invalid){

     string friendName;

      cin >> friendName;
	  User *theUser = theNetwork.find(friendName);
	  if(theUser == NULL){
	    cout << "User does not exist!" << endl;
	    invalid = true;
	  }
	  else{
		  cout<<"Write your wall post!"<<endl;
		  string wallPost;
		  cin >> wallPost;
		  theNetwork.addPost(currentUser,friendName, wallPost, "10:35AM");
		  cout << "Post added successfully!"<< endl;
			  invalid = false;
	  }
     
    }
    cout << "Welcome to VisageLivre, " << currentUser->getRealName() << "!\nSelect an option to begin:\n(1) Create Wall Post\n(2) Delete a Wall Post\n(3) Print Wall\n(4) User Settings\n(0)Logout\n";

    return;
}
void handleDeletePost(){
  cout << "I'm sorry, that isn't a feature yet :(" << endl << endl;
  cout << "Welcome to VisageLivre, " << currentUser->getRealName() << "!\nSelect an option to begin:\n(1) Create Wall Post\n(2) Delete a Wall Post\n(3) Print Wall\n(4) User Settings\n(0)Logout\n";
  
}
void handlePrintWall(){
  currentUser->printWall();
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
    //if(selection == '3')
	  //	theNetwork.printFriends(currentUser->getID());
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



