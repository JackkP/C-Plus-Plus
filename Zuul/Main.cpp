#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"

using namespace std;

int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

int main(){
	char* testRoomName = new char[50];
	strcpy(testRoomName, "Test room name");
	char* testRoomDescription = new char[50];
	strcpy(testRoomDescription, "Test room description");

	Room* testRoom = new Room(testRoomName, testRoomDescription);
	
	cout << "name: " << testRoom->getName() << " descritption: " << testRoom->getDescription() << endl;
	
	char* adjacentRoomName = new char[50];
	strcpy(adjacentRoomName, "Adjacent room name");
	char* adjacentRoomDescription = new char[50];
	strcpy(adjacentRoomDescription, "Adjacent room description");

	Room* adjacentRoom = new Room(adjacentRoomName, adjacentRoomDescription);
	cout << "name: " << adjacentRoom->getName() << " descritption: " << adjacentRoom->getDescription() << endl;

	testRoom->setAdjacent(NORTH, adjacentRoom);
	
	cout << testRoom->getAdjacent(NORTH) << endl;
	cout << testRoom->getAdjacent(EAST) << endl;

	if(testRoom->getAdjacent(EAST) != NULL){
		Room* newRoomPointer = testRoom->getAdjacent(NORTH);
		cout << "name: " << newRoomPointer->getName() << " descritption: " << newRoomPointer->getDescription() << endl;
	}

}
