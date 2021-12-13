#include <iostream>
#include <cstring>
#include <map>
#include "item.h"

using namespace std;

/*const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;*/

class Room{
	public:
		Room(char* newName, char* newDescription);
		void setAdjacent(int direction, Room* room);
		Room* getAdjacent(int direction);
		char* getName();
		char* getDescription();
		~Room();

	private:
		map<int, Room*> adjacent;
		char* name;
		char* description;

};


