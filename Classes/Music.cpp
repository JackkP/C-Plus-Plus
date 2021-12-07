#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;
//constructor with superclass constructor
Music::Music(char* newTitle, int newYear, float newDuration, char* newArtist, char* newPublisher):Media(newTitle, newYear){
	duration = newDuration;
	artist = newArtist;
	publisher = newPublisher;
		
}

//functions for returning values
float Music::getDuration(){
	return duration;
}

char* Music::getPublisher(){
	return publisher;
}

char* Music::getArtist(){
	return artist;
}

//destructor
Music::~Music(){ //delete variables stored as pointer (so they don't take up space on the heap)
	delete[] artist;
	delete[] publisher;
}
