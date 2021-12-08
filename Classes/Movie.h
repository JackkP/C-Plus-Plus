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
		virtual char* getDirector(); //other relevant functions
		virtual float getDuration();
		virtual float getRating();
		void print();

	private: //variables to store attributes of a movie specific only to movies
		char* director;
		float duration;
		float rating;

};

#endif
