#include <iostream>
#include <vector>

#include "functions.hpp" 
#include "Classes.hpp"

using namespace std;

int main () {
string str;
SystemManager* SM = new SystemManager;
User* current_user = new User ("root", "root", User::accessLevels::SuperUser);
SM -> getUsers ().push_back(current_user);
while (cin >> str)
		director (str, SM, current_user);
}
