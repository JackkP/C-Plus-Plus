#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

class Movie : public Media{
	public:
		Movie(char* Title, int Year, char* Director, float duration, float rating);
		char* getDirector();
		float getDuration();
		float getRating();
	
	private:
		char* Director;
		float duration;
		float rating;

};

#endif
