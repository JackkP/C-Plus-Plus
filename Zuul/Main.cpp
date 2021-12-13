#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"

using namespace std;

int main(){
	char* testRoomName = new char[50];
	strcpy("test name", testRoomName);
	char* testRoomDescription = new char[50];
	strcpy("test description", testRoomDescription);


	Room* testRoom = new Room(testRoomName, testRoomDescription);


}
