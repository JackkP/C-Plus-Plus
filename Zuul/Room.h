#ifndef ROOM_H // header guard
#define ROOM_H

#include <iostream>
#include <cstring>
#include <map>
#include "item.h"

using namespace std;

class Room{
	public:
		/*const int NORTH = 0;
		const int EAST = 1;
		const int SOUTH = 2;
		const int WEST = 3;*/

		Room(char* newName, char* newDescription); //constructor
		void setAdjacent(int direction, Room* room); //add a room adjacent
		Room* getAdjacent(int direction); //return the adjacent room
		char* getName(); //return the name of the room
		char* getDescription(); //return the description of the room
		~Room(); //destructor

	private:
		map<int, Room*> adjacent;
		char* name;
		char* description;

};

#endif
