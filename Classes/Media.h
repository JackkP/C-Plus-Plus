#include <iostream>
#include <cstring>

using namespace std;

class Media{
	public:
		Media(char Title[50], int Year);
		char* getTitle();
		int getYear();

	private:
		char* Title;
		int year;

};
