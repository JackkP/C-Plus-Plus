#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

Music::Music(char* newTitle, int newYear, float newDuration, char* newArtist, char* newPublisher):Media(newTitle, newYear){
	duration = newDuration;
	artist = newArtist;
	publisher = newPublisher;
		
}

float Music::getDuration(){
	return duration;
}

char* Music::getPublisher(){
	return publisher;
}

char* Music::getArtist(){
	return artist;
}
Music::~Music(){
	delete[] artist;
	delete[] publisher;
}
