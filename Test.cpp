#include <iostream>
#include <cstring>

using namespace std;

char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};


void printBoard(char board[3][3]){
	cout << "   1   2   3" << endl;
	cout << "a  " << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << " " << endl;
	cout << "  ---+---+---" << endl;
	cout << "b  " << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << " " << endl;
	cout << "  ---+---+---" << endl;
	cout << "c  " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " " << endl;
	return;
}

bool boardFull(char board[3][3]) {
	bool full = true;
	for(int i = 0; i<=2; i++) {
		for(int a = 0; a<=2; a++) {
			if (board[i][a] == ' ') {
				full = false;
			}
		}
	}
	return full;
}

//char checkWin(char & board[3][3]) {
char checkWin(char board [3][3]){
	char rslt = ' ';
	for (int i = 0; i<=2; i++ ) {
                

		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
                        rslt = board[i][0];
                        break;
                }
        }
        for (int i = 0; i<=2; i++ ) {
                

		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') {
                        rslt = board[0][i];
               		break;
		}
        }
	

        if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
                rslt = board[0][0];

        }

        if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
                rslt = board[2][0];
        }
        return rslt;

}

void getMove(char (& rslt)[3]) {
	
	char coords[100];


	//char rslt[3];
	
	while (true){
		

		cin.get(coords, 100);
		cin.get();
	
		cout << "coord[0]: " << coords[0] << " coords[1]: " << coords[1] << endl;
		if ( 49 <= coords[0] && 51 >= coords[0] && 97 <= coords[1] && 99 >= coords[1] && coords[2] == '\0') {
			if (board[coords[0] - 49][coords[1]- 97] == ' ') {
				strcpy(rslt, coords);
				break;
			}
			else {
				cout << "try again" << endl;
			}
		}
		else {
			cout << "try again" << endl;
		}
	}

	return;
}

int main() {
	//board[3][3] = {{'x',' ','o'},{'o','x','x'},{'o','o','o'}};

	printBoard(board);
	
	char winner = checkWin(board);	

	//if (boardFull(board)) cout << "board is full" << endl;
	
	char nextMove[3];

	getMove(nextMove);

	cout << nextMove[3] << endl;

	cout << winner << endl;
	return 0;
}
