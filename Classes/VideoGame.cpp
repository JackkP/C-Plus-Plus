#include <iostream>
#include <cstring>
#include "Media.h"
#include "Videogame.h"

using namespace std;

//constructor inhereting/transfering input parameters to media
Videogame::Videogame(char* newTitle, int newYear, char* newPublisher, float newRating):Media(newTitle, newYear){
	rating = newRating;
	publisher = newPublisher;
	
}

//functions to return stored variables
float Videogame::getRating(){
	return rating;
}

char* Videogame::getPublisher(){
	return publisher;
}

Videogame::~Videogame(){ //destructor
	delete[] publisher; //delete variable stored as pointer
} 
