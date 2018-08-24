#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

const int rows = 20;
const int cols = 70;

class Board
{
public:
	char board[rows][cols]; // creates array
	Board(); //default
	
	void placeBoard(); //sets every spot on board as a '-'
	void showBoard();  //displays board
	void setHuman();   //randomizes human locations
	void setVamp();    //randomizes vampire locations
	void setWere();	   //randomizes werwolf locations
	void updateHV();   //sets conditions for human - vampire
	void updateHW();   //sets condtion for human - werwolf
	void updatesH();   //sets condition for two hoomans
	void checkHuman(); //counts hoomans
};

 Board::Board()
{
	 // default constructor.
}
// places a - to represent dead cells.
void Board::placeBoard()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			board[i][j] = '-';
		}
	}
}
//displays the board
void Board::showBoard()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 70; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}
}
//randomly generates human locations
void Board::setHuman()
{
	int a = 0;
	double maxHuman = 0.3 * (rows * cols) - 1; // max number of humans according to the size of the board.
	while (a <= maxHuman) {
		int x = rand() % rows;
		int y = rand() % cols;
		if (board[x][y] != 'H' && board[x][y] != 'W' && board[x][y] != 'V') {
			a++;  
			board[x][y] = 'H';
		}
	}
}
// randomly generates vampire locations
void Board::setVamp()
{
	int a = 0;
	double maxVamp = 0.1 * (rows * cols) - 1; // max number of vampires according to the size of the board.
	while (a <=  maxVamp) {
		int x = rand() % rows;
		int y = rand() % cols;
		if (board[x][y] != 'V' && board[x][y] != 'W' && board[x][y] != 'H') {
			a++;
			board[x][y] = 'V';
		}
	}
}

// randomly generates werewolf locations
void Board::setWere()
{
	int a = 0;
	double maxWere = 0.1 * (rows * cols) - 1; // max number of werewolfs according to the size of the board.
	while (a <= maxWere) {
		int x = rand() % rows;
		int y = rand() % cols;
		if (board[x][y] != 'W' && board[x][y] != 'H'&& board[x][y] != 'V') {
			a++;
			board[x][y] = 'W';
		}
	}
}

void Board::updateHV()
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			// Because if the board[0][0] checks for the space before it, it will poop.
			//Vamp and human condition
			// Condition if not on edges
			if (board[i][j] == 'H' && i >= 1 && j >= 1 && i < 20 && j < 70) {
				if ((board[i + 1][j] == 'V' || board[i - 1][j] == 'V' || board[i][j + 1] == 'V'
					|| board[i][j - 1] == 'V' || board[i + 1][j + 1] == 'V' || board[i - 1][j - 1] == 'V'
					|| board[i - 1][j + 1] == 'V' || board[i + 1][j - 1] == 'V')
					&& (board[i + 1][j] != 'W' || board[i - 1][j] != 'W' || board[i][j + 1] != 'W' || board[i][j - 1] != 'W'
					|| board[i + 1][j + 1] != 'W' || board[i - 1][j - 1] != 'W' ||
					board[i - 1][j + 1] != 'W' || board[i + 1][j - 1] != 'W')) {
					board[i][j] = 'V';
				}
			}
			// if board i and j are at min corner
			else if (board[i][j] == 'H' && i < 1 && j < 1) {
				if ((board[i + 1][j] == 'V' || board[i][j + 1] == 'V'
					|| board[i + 1][j + 1] == 'V') && (board[i + 1][j] != 'W' || board[i][j + 1] != 'W' || board[i + 1][j + 1] != 'W')) {
					board[i][j] = 'V';
				}
			}
			// if board is at the max corner
			else if (board[i][j] = 'H' && i == 20 && j == 70) {
				if ((board[i - 1][j] == 'V' || board[i][j - 1] == 'V' || board[i - 1][j - 1] == 'V') && (board[i - 1][j] != 'W' || board[i][j - 1] != 'W' || board[i - 1][j - 1] != 'W')) {
					board[i][j] = 'V';
				}
			}
			// if board is at the beginning row but not col
			else if (board[i][j] == 'H' && i == 0 && j > 0) {
				if ((board[i + 1][j] == 'V' || board[i - 1][j] == 'V' || board[i][j + 1] == 'V'
					|| board[i][j - 1] == 'V' || board[i + 1][j + 1] == 'V' 
				    || board[i + 1][j - 1] == 'V')
					&& (board[i + 1][j] != 'W' ||  board[i][j + 1] != 'W' || board[i][j - 1] != 'W'
					|| board[i + 1][j + 1] != 'W' || board[i + 1][j - 1] != 'W')){ 
					board[i][j] = 'V';
				}

			}
		
		}
	}
}

			
void Board::updateHW()
{
	//Werewolf and human
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			if ((board[i][j] == 'H') && 
				(board[i + 1][j] == 'W' || board[i - 1][j] == 'W' || board[i][j + 1] == 'W' || board[i][j - 1] == 'W'
				|| board[i + 1][j + 1] == 'W' || board[i - 1][j - 1] == 'W'
				|| board[i - 1][j + 1] == 'W' || board[i + 1][j - 1] == 'W')
				&& (board[i + 1][j] != 'V' || board[i - 1][j] != 'V' || board[i][j + 1] != 'V' 
				|| board[i][j - 1] != 'V' || board[i + 1][j + 1] != 'V' || board[i - 1][j - 1] != 'V' 
				|| board[i - 1][j + 1] != 'V' || board[i + 1][j - 1] != 'V')) {
				//set human to werewolf
				board[i][j] = 'W';
			}
		}
	}
}
void Board::updatesH()
{
	//human and human
	int numHuman = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			//check for surrounding H
			if (board[i][j] == '-' && board[i + 1][j] == 'H') {
				numHuman++;
				if (numHuman >= 2) {
					board[i][j] = 'H';
				}
			}
			if (board[i][j] == '-' && board[i][j + 1] == 'H') {
				numHuman++;
				if (numHuman >= 2) {
					board[i][j] = 'H';
				}
			}
			if (board[i][j] == '-' && board[i - 1][j] == 'H') {
				numHuman++;
				if (numHuman >= 2) {
					board[i][j] = 'H';
				}
			}
			if (board[i][j] == '-' && board[i][j - 1] == 'H') {
				numHuman++;
				if (numHuman >= 2) {
					board[i][j] = 'H';
				}
			}
			if (board[i][j] == '-' && board[i + 1][j + 1] == 'H') {
				numHuman++;
				if (numHuman >= 2) {
					board[i][j] = 'H';
				}
			}
			if (board[i][j] == '-' && board[i - 1][j - 1] == 'H') {
				numHuman++;
				if (numHuman >= 2) {
					board[i][j] = 'H';
				}
			}
			if (board[i][j] == '-' && board[i + 1][j - 1] == 'H') {
				numHuman++;
				if (numHuman >= 2) {
					board[i][j] = 'H';
				}
			}
			if (board[i][j] == '-' && board[i - 1][j + 1] == 'H') {
				numHuman++;
				if (numHuman >= 2) {
					board[i][j] = 'H';
				}
			}
		}
	}
}
// shows how many hoomans are alive
void Board::checkHuman()
{
	int num = 0;;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			if (board[i][j] == 'H') {
				num++;
			}
	}
	cout << "Humans left: " << num << endl;
}

