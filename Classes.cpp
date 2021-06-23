#include "Classes.hpp"

string User::getUsername () {
	return username;
}
string User::getPassword () {
	return password;
}
User::accessLevels User::getAccessLevel () {
	return accessLevel;
}
void User::setAccessLevel (User::accessLevels aLs) {
	accessLevel = aLs; 
}
/////////////////////////

vector<User*>& Group::getMembers () {
	return members;
} 
string Group::getName () {
	return groupName;
}
/////////////////////////

vector<User*>& SystemManager::getUsers () {
	return users;
}
vector<Group*>& SystemManager::getGroups () {
	return groups;
}
