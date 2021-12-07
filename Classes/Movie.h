#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

//prototype functions for Movie class
class Movie : public Media{ //subclass of Media
	public:
		Movie(char* Title, int Year, char* Director, float duration, float rating);
		~Movie(); //destructor
		char* getDirector(); //other relevant functions
		float getDuration();
		float getRating();
	
	private: //variables to store attributes of a movie specific only to movies
		char* director;
		float duration;
		float rating;

};

#endif
