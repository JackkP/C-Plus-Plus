#include <cstring>
#include <iostream>

using namespace std;

/* Jack Porter
 * Period 1 C Plus Plus
 */


// This method gets a char for A, B, or C value from system input and avoids invalid responses (translated to c++)

char board[3][3] = {{' ', ' ', ' '},{' ', ' ', ' '},{' ', ' ', ' '}};

char getABC(char A, char B, char C) {
        char out;

        char input[100];

        cin.get(input, 100);
	cin.get();

        if ((input[0] == A || input[0] == B || input[0] == C)  && input[1] == '\0') out = input[0];
        else {
                cout << "invalid input please try again" << endl;
                cout << "(" << A << "/" << B << "/" << C << ")" << endl;
                out = getABC(A, B, C);
        }
        return out;
}

// This Method Checks if the board has a three in a row of a value that is not a space, then returns that value (translated to c++)
char checkWin(){
	char rslt;
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


// Printt the board with a nice layout (translated C++)
int printBoard(){
	cout << "   1   2   3" << endl;
	cout << "a  " << board[0][0] << " | " << board[1][0] << " | " << board[2][0] << " " << endl;
	cout << "  ---+---+---" << endl;
	cout << "b  " << board[0][1] << " | " << board[1][1] << " | " << board[2][1] << " " << endl;
	cout << "  ---+---+---" << endl;
	cout << "c  " << board[0][2] << " | " << board[1][2] << " | " << board[2][2] << " " << endl;
	return 0;
}
	
// Check to see if the board is full by looking for spaces (translated to C++)
bool boardFull() {
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
	
/* This method gets a valid move from a player (translated? to c++??)
 * It first checks if the input is a move on the board by converting the characters in the string to their unicode integer counterparts.
 * Since they are ordered, we can just check to make sure that they are within a range of integers. It also checks to make sure that the input is the right length.
 * It then subtracts a value so those numbers are between 0 and 2 (the index range of the board array) and checks that they are indeed empty slots in the board.
 * if all of these are OK, it will return the input as a valid input, if not, we can just implement recursion to start again.
 */
void getMove(char & rslt[3]) {
	
	char coords[3];

	cin.get(coords, 3);
	char rslt[3];
	
	if ( 49 <= coords[0] && 51 >= coords[0] && 97 <= coords[1] && 99 >= coords[1] && coords.length() == 2) {
		if (board[coords[0] - 49][coords[1]- 97].equals(" ")) {
			strcpy(rslt, coords);
		}
		else {
			cout << "try again" << endl;
			rslt = getMove(board);
		}
	}
	else {
		cout << "try again" << endl;
		rslt = getMove(board, scanner);
	}
	return rslt;
}


int main() { // should be translated to c++
	
		
	cout << "Welcome to Command Line Tic Tac Toe \n" << endl;
	cout << "New Game" << endl;
	cout << "===================";
	
	int scoreX = 0;
	int scoreO = 0;
	int draws = 0;
			
	
	//continue playing while in this loop
	while (true) {
		char board[][] = {{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}};			
		cout << "Player 1 (x) starts" <endl;
		char player[5] = "1 (x)";
		
		char scoreXDisp[6] = " wins";
		char scoreODisp[6] = " wins";
		char drawsDisp[7] = " draws";
		
		while (true) {
			cout << "#=#=#=#=#=#=#=#=#=#=#  Player " << player << " type coordinates of move (number first and capital letters eg 3b)" << endl;
			printBoard();				
			char move[3];
			getMove(move);
			
			if (strcmp(player, "1 (x)") == 0) {
				board[move[0] - 49][move[1]- 97] = 'x';
				player = "2 (o)";
			}
			else if (strcmp(player, "2 (o)") == 0) {
				board[move[0]- 49][move[1]- 97] = "o";
				player = "1 (x)";
			}
			
			char lastWin = checkWin();				
			if (lastWin == 'x') {
				scoreX += 1;
				printBoard();
				break;
			}
			else if (lastWin == 'o') {
				scoreO += 1;
				printBoard();
				break;
			}
			if (boardFull(board)) {
				draws += 1;
				printBoard();
				break;
			}
		}
		
		if (scoreX == 1) {
			scoreXDisp = " win";
		}
		if (scoreO == 1) {
			scoreODisp = " win";
		}
		if (draws == 1) {
			drawsDisp = " win";
		}
		
		cout << endl;
		cout << "Player 1 (x): " << scoreX << scoreXDisp << " | Player 2 (o): " << scoreO << scoreODisp << " | Draws: " << draws << drawsDisp << endl;
		cout << "============================================================" << endl;
		cout << "Type n for new game, r to reset scores, or q to quit." << endl;
		char next = getABC('n', 'r', 'q');
		if (next == 'r') {
			scoreX = 0;
			scoreO = 0;
			draws = 0;
		}
		else if(next == 'q') {
			break;
		}
	}
	
}
