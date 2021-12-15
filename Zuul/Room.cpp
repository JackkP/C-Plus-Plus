#include <iostream>
#include <cstring>
#include "Item.h"
#include "Room.h"
#include <map>

using namespace std;

Room::Room(char* newName, char* newDescription){ //constructor sets name and description
	name = newName;
	description = newDescription;

	for(int i = 0; i < 4; i++) adjacent.insert(pair<int, Room*>(i, NULL)); 
}
void Room::setAdjacent(int direction, Room* room){ //add a room to the map of adjacent rooms
	adjacent.erase(direction);
	adjacent.insert(pair<int, Room*>(direction, room)); //add the room to the map
}

Room* Room::getAdjacent(int direction){
	return adjacent.at(direction);
}

char* Room::getName(){
	return name;
}

char* Room::getDescription(){
	return description;
}

Room::~Room(){
	delete name;
	delete description;
}
