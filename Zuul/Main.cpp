#include <iostream>
#include <cstring>
#include "Room.h"
#include "Item.h"

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

/* Jack Porter, December 2021
 *
 * Zuul, the text based game!
 * The player starts as a remote submarine outside the titanic and tries to retrieve the captain's journal and engineer's notebook
 * User interface could use some work, it's not especially intuitive.
 * Look at the map in the Zuul folder to make life easier becuase remembering the layout can be kind of hard.
 */

bool contains(vector<Item*> vect, Item* item){
	for(vector<Item*>::iterator ptr = vect.begin(); ptr < vect.end(); ptr++){
		if((*ptr) == item) return true;
	}
	return false;
}

int main(){

	vector<Item*> inventory; //items in inventory
	char next[50]; //next thing to do (user input here)
	Room* current; //pointer to current room
	
	//map setup (this is a lot of repetitive code)
	char dstart[100]; //start
	strcpy(dstart, "in the black ocean outside the ship.");
	Room* start = new Room(dstart);
	
	char dhall1[100]; //hall1
	strcpy(dhall1, "in a long hall with many locked doors.");
	Room* hall1 = new Room(dhall1);
	start->setAdjacent(WEST, hall1);
	hall1->setAdjacent(EAST, start);

	char dbdrm1[100]; //bedroom 1
	strcpy(dbdrm1, "in a beautiful bedroom with an open window and a lot of rotting and broken furniture.");
	Room* bdrm1 = new Room(dbdrm1);
	hall1->setAdjacent(NORTH, bdrm1);
	bdrm1->setAdjacent(SOUTH, hall1);

	char njwlrybx[50]; //jewlery box
	strcpy(njwlrybx, "cracked jewlery box");
	Item* jwlrybx = new Item(njwlrybx);
	bdrm1->addItem(jwlrybx);
	
	char dblrm [200]; //ballroom
	strcpy(dblrm, "in the main ballroom. Chairs have all fallen towards the wall and you can feel how tilted the wreck really is.");
	Room* blrm = new Room(dblrm);
	hall1->setAdjacent(WEST, blrm);
	blrm->setAdjacent(EAST, hall1);

	char nbrknchair[50]; //broken chair
	strcpy(nbrknchair, "mangled chair");
	Item* brknchair = new Item(nbrknchair);
	blrm->addItem(brknchair);

	char dlobby[200]; //lobby
	strcpy(dlobby, "in the main lobby. The carpet is floating in places and a pile of broken marble sculptures sits in the corner. An angler fish stares at you from a dark corner.");
	Room* lobby = new Room(dlobby);
	blrm->setAdjacent(NORTH, lobby);
	lobby->setAdjacent(SOUTH, blrm);
	
	char dmstrs[200]; //main stairs
	strcpy(dmstrs, "at the main double staircase. You recognise the domed ceiling from the photos, but are more awed by the collapsed left staircase.");
	Room* mstrs = new Room(dmstrs);
	lobby->setAdjacent(NORTH, mstrs);
	mstrs->setAdjacent(SOUTH, lobby);

	char dhall2[100]; //hall 2 
	strcpy(dhall2, "in a short hallway with only three open doors.");
	Room* hall2 = new Room(dhall2);
	mstrs->setAdjacent(NORTH, hall2);
	hall2->setAdjacent(SOUTH, mstrs);

	char dbdrm2[150]; //bedroom 2
	strcpy(dbdrm2, "in a bedroom with two bunkbeds and a large chest. Everything is metal but the lead paint prevents rust in some areas.");
	Room*  bdrm2 = new Room(dbdrm2);
	hall2->setAdjacent(EAST, bdrm2);
	bdrm2->setAdjacent(WEST, hall2);
	
	char dbthrm[100]; //bathroom
	strcpy(dbthrm, "in a wood lined bathroom, but very little wood remains.");
	Room* bthrm = new Room(dbthrm);
	hall2->setAdjacent(WEST, bthrm);
	bthrm->setAdjacent(EAST, hall2);
	
	char ngldmir[50]; //gold mirror
	strcpy(ngldmir, "gold mirror");
	Item* gldmir = new Item(ngldmir);
	bthrm->addItem(gldmir);

	char dcptnrm[150]; //captains room
	strcpy(dcptnrm, "in the captains quarters, furnished lavishly. The iron bedframe lies in the center of the room, rusted through in places");
	Room* cptnrm = new Room(dcptnrm);
	hall2->setAdjacent(NORTH, cptnrm);
	cptnrm->setAdjacent(SOUTH, hall2);

	char dcptnclst[100]; //captains personal closet
	strcpy(dcptnclst, "in the captain's personal closet which is filled with coathangers and scraps of cloth");
	Room* cptnclst = new Room(dcptnclst);
	cptnrm->setAdjacent(EAST, cptnclst);
	cptnclst->setAdjacent(WEST, cptnrm);

	char ncptnjrnl[50]; //captain's journal
	strcpy(ncptnjrnl, "captain's journal");
	Item* cptnjrnl = new Item(ncptnjrnl);
	cptnclst->addItem(cptnjrnl);

	char dsstrs[100]; //small stairs
	strcpy(dsstrs, "in a tight staircase with metal handrails");
	Room* sstrs = new Room(dsstrs);
	blrm->setAdjacent(WEST, sstrs);
	sstrs->setAdjacent(EAST, blrm);

	char dengrm[100]; //engine room
	strcpy(dengrm, "in the main engine room. Coal covers the floor.");
	Room* engrm = new Room(dengrm);
	sstrs->setAdjacent(NORTH, engrm);
	engrm->setAdjacent(SOUTH, sstrs);
	
	char nwrench[50]; //wrench
	strcpy(nwrench, "rusty wrench");
	Item* wrench = new Item(nwrench);
	engrm->addItem(wrench);

	char nengbk[50]; //engineer's notebook
	strcpy(nengbk, "engineer's notebook");
	Item* engbk = new Item(nengbk);
	engrm->addItem(engbk);

	char ddinhal[150]; //dining hall
	strcpy(ddinhal, "in the dining hall. Tables and chairs are scattered and the chandelier has long since fallen to the floor.");
	Room* dinhal = new Room(ddinhal);
	blrm->setAdjacent(SOUTH, dinhal);
	dinhal->setAdjacent(NORTH, blrm);

	char dlounge[100]; //lounge
	strcpy(dlounge, "in a large lounge with windows that look into the darkness above.");
	Room* lounge = new Room(dlounge);
	dinhal->setAdjacent(WEST, lounge);
	lounge->setAdjacent(EAST, dinhal);

	char dkitch[100]; //kitchen
	strcpy(dkitch, "in the main kitchen. The tile on the floor is virtually undamaged.");
	Room* kitch = new Room(dkitch);
	dinhal->setAdjacent(SOUTH, kitch);
	kitch->setAdjacent(NORTH, dinhal);

	char nknife[50]; //knife
	strcpy(nknife, "rusty knife");
	Item* knife = new Item(nknife);
	kitch->addItem(knife);

	char dpntry[150]; //pantry
	strcpy(dpntry, "in a pantry filled with algae. Tiny fish flit back and forth everywhere, and it's hard to see.");
	Room* pntry = new Room(dpntry);
	kitch->setAdjacent(EAST, pntry);
	pntry->setAdjacent(WEST, kitch);

	
	cout << "\nWelcome to Zuul!\n\nYou are piloting a newly developed remote submarine through the wreck of the titanic\nThe mission you've been assigned is to retrieve the captain's journal and the engineer's notebook and return to the start. Earn extra points by bringing back the other items! Good luck, you're going to need it!" << endl;

	current = start;
	while(true){ //game loop
	
		cout << "========================================\n You are " << current->getDescription() << "\n Items: "; //what room you're in
		current ->printItems(); //print the items in the room
		
		cout << "\n Exits: ";
		if(current->getAdjacent(NORTH) != NULL) cout << "north ";
		if(current->getAdjacent(EAST) != NULL) cout << "east ";
		if(current->getAdjacent(SOUTH) != NULL) cout << "south ";
		if(current->getAdjacent(WEST) != NULL) cout << "west " << endl;

		cout<<"\n - type help for commands - \n========================================" << endl; 
	
		cin.get(next, 50); //get next command
		cin.get();


		if(strcmp(next, "help") == 0) { //print the help menu
			cout << "========================================\n\n'go' - go into an adjacent room\n'grab' - grab an item by name\n'drop' - leave an item by name\n'inventory' - print inventory\n'quit' - exit the program\n" << endl;
		}
	
		else if(strcmp(next, "go") == 0){
			cout << "go where? (N/E/S/W)" << endl;
			int direction = 0; //direction of room to go to
			
			while(true){
				cin.get(next, 50);
				cin.get();

				//I'm too lazy to find a better way to check if the reply is a valid exit
				if(current->getAdjacent(NORTH) != NULL && strcmp(next, "N") == 0) {direction = NORTH; break;}
				if(current->getAdjacent(EAST) != NULL && strcmp(next, "E") == 0) {direction = EAST; break;}
				if(current->getAdjacent(SOUTH) != NULL && strcmp(next, "S") == 0) {direction = SOUTH; break;}
				if(current->getAdjacent(WEST) != NULL && strcmp(next, "W") == 0) {direction = WEST; break;}

				cout << "Not an exit, try again (N/E/S/W)" << endl;
			}
			current = current->getAdjacent(direction); //update the room to a new room
		}
	
		else if(strcmp(next, "inventory") == 0){
			cout << "You are carrying: " << endl;
			for(vector<Item*>::iterator ptr = inventory.begin(); ptr<inventory.end(); ptr++){ //print every item in inventory
				cout << (*ptr)->getName() << ", ";
			}
			cout << endl;
		}
	
		else if(strcmp(next, "grab") == 0){ //take an item from the room
			cout << "grab what? (type the name of the item)" << endl;
			cin.get(next, 50);
			cin.get();
			Item* takenItem = current->takeItem(next); //create a new item pointer for that item
			if(takenItem == NULL) cout << "That item is not in this room" << endl; //if the item is not in the room then send a message
			else inventory.push_back(takenItem); //otherwise add item to the inventory
			
		}
	
		else if(strcmp(next, "drop") == 0){ //add an item to the room
			cout << "drop what?" << endl;
			cin.get(next, 50);
			cin.get();
			bool dropped = false;
			for(vector<Item*>::iterator ptr = inventory.begin(); ptr<inventory.end(); ptr++){ //for every item in the vector
				if(strcmp((*ptr)->getName(), next) == 0 ){ //check to see if the name matches
					current->addItem((*ptr)); //add to the current room
					inventory.erase(ptr); //remove from inventory
					dropped = true; //update to deal with error message
					break;
				}
			}
			if(!dropped) cout << "You don't have that item with you" << endl; //no items matched
		}
	
		else if(strcmp(next, "quit") == 0){
			break;
		}
	
		else{
			cout << "not a valid command" << endl;
		}
		
		if(current == start && contains(inventory, cptnjrnl) && contains(inventory, engbk)){ //if you are in the start room and have both journals
			cout << "Congratulations!! Mission accomplished" << endl;
			
			int numItems = 0; //count the number of items
			for(vector<Item*>::iterator ptr = inventory.begin(); ptr < inventory.end(); ptr ++){ //count the number of items picked up
				numItems++;
			}
			cout << "You slowly float to the surface with " << numItems << " out of the 7 items, congrats!" << endl;
			break;
		}


	}	
	return 0;
}
