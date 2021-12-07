#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

//constructor from superclass
class Videogame : public Media{
	public:
		Videogame(char* Title, int Year, char* Publisher, float Rating);
		~Videogame(); //destructor
		char* getPublisher(); //other functions
		float getRating();
		

	private: //variables specific to videogames
                char* publisher;
		float rating;

};
