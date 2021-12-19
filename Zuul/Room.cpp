#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include "Item.h"
#include "Room.h"

/* Room Class (stores a map for adjacent rooms and a vector for items in the room)
 * 
 * Functions:
 *  constructor, 24
 *  addItem, 30 - adds an item to the list
 *  takeItem, 34 - removes an item from the list and returns a pointer to it
 *  printItems, 44 - prints all items in the list
 *  setAdjacent, 50 - adds a room pointer to the map with direction key
 *  getAdjacent, 56 - returns a room pointer to adjacent room given direction key
 *  getDescription, 60 - returns char pointer to description
 *  destructor, 65
 */

using namespace std;

Room::Room(char* newDescription){ //constructor sets name and description
	description = newDescription;

	for(int i = 0; i < 4; i++) adjacent.insert(pair<int, Room*>(i, NULL)); //set all directions (N, E, S, W) to zero;
}

void Room::addItem(Item* item){ //add item pointer to the vector
	items.push_back(item);
}

Item* Room::takeItem(char* name){ //removes item from vector by name and returns a pointer to it
	for(vector<Item*>::iterator ptr = items.begin(); ptr<items.end(); ptr++){ //for every item in the vector
		if(strcmp((*ptr)->getName(), name) == 0 ){ //check the name
			items.erase(ptr);
			return (*ptr);
		}
	}
	return NULL; //otherwise retun null (no items match name given)
}

void Room::printItems(){ //print all the items seperated by spaces
	for(vector<Item*>::iterator ptr = items.begin(); ptr<items.end(); ptr++){
		cout << (*ptr)->getName() << ", ";
	}
}

void Room::setAdjacent(int direction, Room* room){ //add a room to the map of adjacent rooms
	adjacent.erase(direction); //remove anything that may already be in  that direction
	adjacent.insert(pair<int, Room*>(direction, room)); //add the room to the map
}

Room* Room::getAdjacent(int direction){
	return adjacent.at(direction); //return a pointer to the adjacent room
}

char* Room::getDescription(){
	return description;
}

Room::~Room(){ //destructor
	delete description;
}
