#include <iostream>
#include <cstring>
#include "Media.h"

using namespace.std;

class Music: public Media{
	public:
		Music(char Title[50], int Year, float duration, char artist[50], char Publisher[50]):Media(Title, Year);
		char* getArtist();
		char* getPublisher();
		float getDuration();

	private:
		char* artist;
                char* publisher;
		float duration;

};
