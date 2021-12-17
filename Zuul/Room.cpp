#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#include "Room.h"

using namespace std;

Room::Room(char* newName, char* newDescription){ //constructor sets name and description
	name = newName;
	description = newDescription;

	for(int i = 0; i < 4; i++) adjacent.insert(pair<int, Room*>(i, NULL)); //set all directions (N, E, S, W) to zero;
}

void Room::addItem(Item* item){
	
}

void Room::takeItem(char* name){

}

void Room::printItems(){

}

void Room::setAdjacent(int direction, Room* room){ //add a room to the map of adjacent rooms
	
	adjacent.erase(direction); //remove anything that may already be in  that direction
	adjacent.insert(pair<int, Room*>(direction, room)); //add the room to the map
}

Room* Room::getAdjacent(int direction){
	return adjacent.at(direction); //return a pointer to the adjacent room
}

char* Room::getName(){ //destructor
	return name;
}

char* Room::getDescription(){ //destructor
	cout << description << endl;
	return description;
}

Room::~Room(){ //destructor
	delete name;
	delete description;
}
