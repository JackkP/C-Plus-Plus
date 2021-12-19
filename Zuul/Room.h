#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>
#include <map>
#include <vector>
#include "item.h"

using namespace std;

class Room{
	public:
		Room(char* newDescription); //constructor
		
		void setAdjacent(int direction, Room* room); //add an adjacent room
		Room* getAdjacent(int direction); //return the adjacent room
		
		char* getDescription(); //return the description of the room
		
		void addItem(Item* item); //add an item to a room
		void printItems(); //print the items in a room
		Item* takeItem(char* name); //remove an item from a room and return a pointer to it

		~Room();

	private:
		vector<Item*> items; //to keep track of items in the room
		map<int, Room*> adjacent; //to keep track of adjacent rooms
		
		char* description;

};

#endif
