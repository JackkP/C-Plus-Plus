#ifndef ROOM_H // header guard
#define ROOM_H

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "item.h"

using namespace std;

class Room{
	public:
		Room(char* newName, char* newDescription); //constructor
		
		void setAdjacent(int direction, Room* room); //add an adjacent room
		Room* getAdjacent(int direction); //return the adjacent room
		
		char* getName(); //return the name of the room
		char* getDescription(); //return the description of the room
		
		~Room(); //destructor

	private:
		vector<Item*> items; //to keep track of items in the room
		map<int, Room*> adjacent; //to keep track of adjacent rooms
		
		char* name;
		char* description;

};

#endif
