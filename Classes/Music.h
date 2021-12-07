#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

//prototype functions for Movie class
class Music : public Media{ //subclass of Media
	public:
		Music(char* Title, int Year, float duration, char* artist, char* Publisher);
		~Music(); //destructor
		char* getArtist(); //other functions
		char* getPublisher();
		float getDuration();
		

	private: //variables to store attibutes specific to music
		char* artist;
                char* publisher;
		float duration;

};
