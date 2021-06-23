#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <vector>

using namespace std;

class User {
public :
	enum class accessLevels  {SuperUser, Admin, NormalUser}; 
	User (string _username, string _password, accessLevels aLs) : username(_username), password(_password), accessLevel(aLs) {

	}
	string getUsername ();
	string getPassword ();
	accessLevels getAccessLevel ();
	void setAccessLevel (accessLevels);
private:
	accessLevels accessLevel;
	string username, password;
};

class Group {
public:
	Group (string _groupName, User* _creator) : groupName(_groupName), creator(_creator) {
		members.push_back (creator);
	}
	vector<User*>& getMembers (); 
	string getName ();
private:
	User* creator;
	vector<User*> members;
	string groupName;
};


class SystemManager {
public:
	vector<User*>& getUsers ();
	vector<Group*>& getGroups ();
private:
	vector<User*> users;
	vector<Group*> groups;
};

#endif