#include <iostream>
#include <cstring>
#include "Media.h"

using namespace std;

//constructor from superclass
class Videogame : public Media{
	public:
		Videogame(char* Title, int Year, char* Publisher, float Rating);
		~Videogame(); //destructor
		virtual char* getPublisher(); //other functions
		virtual float getRating();
		void print();
		

	private: //variables specific to videogames
                char* publisher;
		float rating;

};
