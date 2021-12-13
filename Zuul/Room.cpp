#include <iostream>
#include <cstring>
#include "Item.h"
#include "Room.h"
#include <map>

/*const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;*/

using namespace std;

Room::Room(char* newName, char* newDescription){
	name = newName;
	description = newDescription;
}
void setAdjacent(int direction, Room* room){
	map.insert(diresction, room); 
}

Room* getAdjacent(int direction){
	return adjacent.at(direction);
}

char* getName(){
	return name;
}

char* getDescription(){
	return description;
}

~Room(){
	delete name;
	delete description;
}




}
