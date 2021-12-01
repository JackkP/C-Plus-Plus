#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Music : public Media{
	public:
		Music(char* Title, int Year, float duration, char* artist, char* Publisher);
		~Music();
		char* getArtist();
		char* getPublisher();
		float getDuration();
		

	private:
		char* artist;
                char* publisher;
		float duration;

};
