#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;

//Item class, literally just an object with a name, no reason for this to even be a class
 

Item::Item(char* newName){
	name = newName;
}

char* Item::getName(){
	return name;
}

Item::~Item(){ //destructor deletes name object stored as pointer
	delete[] name;
}
