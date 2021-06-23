#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

#include "Classes.hpp"
#include "functions.hpp"
#include "exceptions.hpp"

using namespace std;

void add_user (SystemManager*&);

void login (SystemManager*&, User*&);

void logout (User*&);

void add_group (SystemManager*&, User*&);

void add_to_group (SystemManager*&, User*&);

void promote (SystemManager*&, User*&);

void demote (SystemManager*&, User*&);

void director (string, SystemManager*&, User*&);

#endif