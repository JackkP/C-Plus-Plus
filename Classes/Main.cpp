#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movie.h"
#include "Music.h"
#include <vector>

using namespace std;


int main(){
	
	vector<Media*> medais;

	cout << "Welcome to the Media Database!\n========================================" << endl;
	
	char next[30];
	while(true){
		cout << "type help for commands" << endl;
		cin.get(next, 30);
		cin.get();
		if(strcmp(next, "help") == 0){
			cout << "\n========================================\n\nadd - add a media to the database\nprint - list everything in the database\nsearch - search by name or by title\ndelete - delete a media by title and year\nquit - exit the program\n\n========================================" << endl;
		}
		else if(strcmp(next, "add") == 0){
				
		}
		else if(strcmp(next, "print") == 0){

		}
		else if(strcmp(next, "search") == 0){
			
		}
		else if(strcmp(next, "delete") == 0){

		}
		else if(strcmp(next, "quit") == 0){ 

		}
		else{

		}

	}

}
