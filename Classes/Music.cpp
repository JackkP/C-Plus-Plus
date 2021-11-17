#include <iostream>
#include <cstring>
#include "Media.h"
#include "Music.h"

using namespace std;

Music::Music(char Title[50], int Year, float newDuration, char newArtist[50], char newPublisher[50]):Media(Title, Year){
	duration = newDuraton;
	artist = newArtist;
	publisher = newPublisher;
		
}

float Music::getDuration(){
	return duration;
}

char* Music::getArtist(){
        return Title;
}

char* Music::getPublisher(){
	return publisher
}
