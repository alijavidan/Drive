#include "functions.hpp"

void add_user (SystemManager* &SM) {
	string username, password;
	cin >> username >> password;

	User* user = new User(username, password, User::accessLevels::NormalUser);
	
	SM -> getUsers ().push_back (user);
	SM -> getGroups ().push_back (new Group (username, user));
}
void login (SystemManager* &SM, User* &current_user) {
	string username, password;
	cin >> username >> password;

	if (current_user != NULL)
		throw unableLogin ();

	for (int i = 0; i < SM -> getUsers ().size (); i++)
		if (SM -> getUsers ()[i] -> getUsername () == username && SM -> getUsers ()[i] -> getPassword () == password)
			current_user = SM -> getUsers ()[i]; 
}
void logout (User* &current_user) {
	current_user = NULL;
}
void add_group (SystemManager* &SM, User* &current_user) {
	string groupName;
	cin >> groupName;
	SM -> getGroups ().push_back(new Group(groupName, current_user));
}
void add_to_group (SystemManager* &SM, User* &current_user) {

	string groupName, username;
	cin >> groupName >> username;

	bool check = false;
	for (int i = 0; i < SM -> getGroups ().size (); i++)
		if (SM -> getGroups ()[i] -> getName () == groupName)
			for (int j = 0; j < SM -> getGroups ()[i] -> getMembers ().size (); j++)
				if (SM -> getGroups ()[i] -> getMembers ()[j] == current_user)
					check = true;

	if (!check)
		throw unableUser ();

	User* user;
	for (int i = 0; i < SM -> getUsers ().size (); i++)
		if (SM -> getUsers ()[i] -> getUsername () == username)
			user = SM -> getUsers ()[i];

	for(int i = 0; i < SM -> getGroups ().size (); i++)
		if (SM -> getGroups ()[i] -> getName () == groupName)
			SM -> getGroups ()[i] -> getMembers ().push_back (user);
}

void userList (SystemManager* &SM, User* &current_user) {
	if (current_user -> getAccessLevel () == User::accessLevels::SuperUser || current_user -> getAccessLevel () == User::accessLevels::Admin)
		for (int i = 0; i < SM -> getUsers ().size (); i++)
			cout << SM -> getUsers ()[i] -> getUsername () << endl;
	else
		throw unableUser ();
}

void promote (SystemManager* &SM, User* &current_user) {
	string username;
	cin >> username;

	if (current_user -> getAccessLevel () == User::accessLevels::SuperUser) {
		for (int i = 0; i < SM -> getUsers ().size (); i++)
			if (SM -> getUsers ()[i] -> getUsername () == username)
				if (SM -> getUsers ()[i] -> getAccessLevel () == User::accessLevels::Admin)
					SM -> getUsers ()[i] -> setAccessLevel (User::accessLevels::SuperUser);
				else if (SM -> getUsers ()[i] -> getAccessLevel () == User::accessLevels::NormalUser)
					SM -> getUsers ()[i] -> setAccessLevel (User::accessLevels::Admin);	
				else 
					throw requireDismatch ();
	}
	else
		throw unableUser ();
}

void demote (SystemManager* &SM, User* &current_user) {
	string username;
	cin >> username;

	if (current_user -> getAccessLevel () == User::accessLevels::SuperUser) {
		for (int i = 0; i < SM -> getUsers ().size (); i++)
			if (SM -> getUsers ()[i] -> getUsername () == username)
				if (SM -> getUsers ()[i] -> getAccessLevel () == User::accessLevels::Admin)
					SM -> getUsers ()[i] -> setAccessLevel (User::accessLevels::NormalUser);
				else if (SM -> getUsers ()[i] -> getAccessLevel () == User::accessLevels::SuperUser)
					SM -> getUsers ()[i] -> setAccessLevel (User::accessLevels::Admin);	
				else 
					throw requireDismatch ();
	}
	else
		throw unableUser ();
}

void director (string str, SystemManager* &SM, User* &current_user) {
	try {
		if (str == "add_user")
			add_user (SM);
		else if (str == "login")
			login (SM, current_user);
		else if (str == "logout")
			logout (current_user);
		else if (str == "add_group")
			add_group (SM, current_user);
		else if (str == "add_to_group")
			add_to_group (SM, current_user);
		else if (str == "promote")
			promote (SM, current_user);
		else if (str == "demote")
			demote (SM, current_user);
		else if (str == "userlist")
			userList (SM, current_user);
	} catch (unableUser uU) {
		cout << "Unable User\n";
	} catch (requireDismatch rD) {
		cout << "Targeted User Does Not Match Promote/Demote Requires\n";
	} catch (unableLogin uL) {
		cout << "Unable to login\n";
	}
}