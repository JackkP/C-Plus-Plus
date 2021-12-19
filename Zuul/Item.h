#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <cstring>

using namespace std;

class Item{
	public:
		Item(char* newName); //constructor
		char* getName(); //return name

		~Item(); //destructor

	private:
		char* name; //the only thing that needs to be stored is the name of the item
};

#endif
