#include <iostream>
#include <cstring>
#include "item.h"

using namespace std;
Item::Item(char* newName){
	name = newName;
}

char* Item::getName(){
	return name;
}

Item::~Item(){ //destructor deletes name object stored as pointer
	delete[] name;
}
