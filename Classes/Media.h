#ifndef MEDIA_H
#define MEDIA_H
#include <iostream>
#include <cstring>

using namespace std;

class Media{
	public:
		Media(char* Title, int Year);
		~Media();
		char* getTitle();
		int getYear();

	protected:
		char* title;
		int year;

};

#endif
