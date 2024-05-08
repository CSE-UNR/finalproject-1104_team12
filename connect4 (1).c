// Author: Chris McBean, Zachary Rowley
// Program: Connect
// Final group project




#include <stdio.h>
#include <stdbool.h>

#define ROWS 6
#define COLMS 7
#define MAX_PLAYERS 2

char board[ROWS][COLMS];
char players[MAX_PLAYERS] = {'X', 'O'};

void initializeBoard() {
	for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLMS; j++) {
		board[i][j] = '.';
		}
	}
}

void printBoard() {
	for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLMS; j++) {
		printf("%c ", board[i][j]);
		}
	}
}

bool makeMove(int column, char player) {
	if (column < 0 || column >= COLMS) {
		return false;
	}

	for (int i = ROWS - 1; i >= 0; i--) {
		if (board[i][column] == '.') {
			board[i][column] = player;
	return true;
	}
}

	
	}

bool checkForWin(char player) {
// Check horizontal, vertical, and diagonal conditions
	for (int i = 0; i < ROWS; i++) {
	for (int j = 0; j < COLMS; j++) {
		if (j <= COLMS - 4 && board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player) {
	return true;
}
		if (i <= ROWS - 4 && board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player) {
	return true;
}
	if (i <= ROWS - 4 && j <= COLMS - 4 && board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player) {
	return true;
}
	if (i >= 3 && j <= COLMS - 4 && board[i][j] == player && board[i - 1][j + 1] == player && board[i - 2][j + 2] == player && board[i - 3][j + 3] == player) {
	return true;
		}
	}
}
	return false;
}

int main() {
int currentPlayer = 0;
int column;
bool gameRunning = true;

	initializeBoard();
	printBoard();

	while (gameRunning) {
		printf("Player %c, enter column (0-6) to play: ", players[currentPlayer]);
		scanf("%d", &column);

	if (makeMove(column, players[currentPlayer])) {
		printBoard();
	if (checkForWin(players[currentPlayer])) {
		printf("Player %c wins!\n", players[currentPlayer]);
			gameRunning = false;
		}
			currentPlayer = (currentPlayer + 1) % MAX_PLAYERS;
	} 		
		else {
		printf("Column full or invalid, try again.\n");
	}
}

	return 0;
}

