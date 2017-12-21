//This is a simple Tic-Tac-Toe Game, user vs. cpu
//Author: Micah Brame

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cpustrat.h"
#include "isWin.h"
using namespace std;

void printboard (char board[][3]) //prints the board
{
	for(int i = 0; i<3; i++)
	{
		cout << "             ";
		for(int j=0; j<3; j++)
		{
			cout<<board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

char user (char board[][3]) //code for user playing
{
	int userrow, usercolumn;
	
	cout << "          Which row? ";
	cin >> userrow;
	userrow -=1;

	cout << "\n         Which column? ";
	cin >> usercolumn;
	usercolumn -=1;
	
	if (board[userrow][usercolumn] !='-' || usercolumn >2)
	{
		cout << "\n      You can't play here\n" << endl;
		user(board);
	}
	else
	{
		return board[userrow][usercolumn] = 'X';
	}
}

int main() 
{
	char again = 'Y';
	cout << "\n****Welcome to Tic-Tac-Toe****\n";
	cout << "          You are X's          \n";
	cout << "       Here is the board:      \n";
	do
	{
		srand(time(NULL));
		char board[3][3] = {{'-','-','-'},{'-','-','-'},{'-','-','-'}};
		printboard(board);
		
	
		do{
			user(board);
			printboard(board);
			if(isWin(board))
			{
				break;
			}
			cpu(board);
			cout << "           CPU plays:     \n";
			printboard(board);

		}while(!isWin(board));
		
		cout << "      Play again? Y or N: ";
		cin >> again;
		cout << endl;

	}while(again == 'Y' || again == 'y');
}