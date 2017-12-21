//code for the cpu's strategy for tictactoe
#include <iostream>
using namespace std;

char cpuStrategy(char board[][3], int & counter) //gives CPU ability to block a 3-in-a-row chance
{
	int a = 0, b=0, c=0, d=0, e=0, f=0, g=0, h=0;
	int same = 3, alsoSame = 3;
	int xRowCoord, yRowCoord, xColCoord, yColCoord, xDownRightDiagCoord, 
		yDownRightDiagCoord, xUpLeftDiagCoord, yUpLeftDiagCoord;
	for(int i = 0; i<3; i++)
	{	
		for(int j = 0; j<3; j++)
		{
			//checking rows for two X's 
			if(board[i][j] == 'X')
			{	a++; 	}
			else if(board[i][j] == '-')
			{
				xRowCoord = i;
				yRowCoord = j;
			}
			else if(board[i][j] == 'O') //accounts for two X's and one O situation
			{	b++;	}
			
			//checks columns for two X's
			if(board[j][i] == 'X')
			{	c++;	}
			else if(board[j][i] == '-')
			{
				xColCoord = j;
				yColCoord = i;
			}
			else if(board[j][i] == 'O') //accounts for two X's and one O situation
			{	d++;	}
			
			//checks diagonals for two X's
			
			//checks down to the right
			if(board[j][j] == 'X' && j != same) 
			{
				same = j;
				e++;
			}
			else if(board[j][j] == '-')
			{
				xDownRightDiagCoord = j;
				yDownRightDiagCoord = j;
			}
			else if(board[j][j] == 'O')
			{	f++;	}

			//checks up to the left
			int k = 2-j;
			if(board[k][j] == 'X' && k != alsoSame)
			{
				alsoSame = k;
				g++;
			}
			else if(board[k][j] == '-')
			{
				xUpLeftDiagCoord = k;
				yUpLeftDiagCoord = j;
			}
			else if(board[k][j] == 'O')
			{	h++;	}
		}
		if(a == 2 && b == 0)
		{
			counter++;
			return board[xRowCoord][yRowCoord] = 'O';
			break;
		}
		if(c == 2 && d == 0)
		{
			counter++;
			return board[xColCoord][yColCoord] = 'O';
			break;
		}
		if(e == 2 && f == 0)
		{
			counter++;
			return board[xDownRightDiagCoord][yDownRightDiagCoord] = 'O';
			break;
		}
		if(g == 2 && h == 0)
		{
			counter++;
			return board[xUpLeftDiagCoord][yUpLeftDiagCoord] = 'O';
			break;
		}
		a=0, b=0, c=0, d=0;
	}
}

char cpu (char board[][3]) //cpu's code
{
	int choice1 = rand()%3;
	int choice2 = rand()%3;
	int counter = 0;

	cpuStrategy(board, counter);
	
	if(counter == 0)
	{
		if(board[choice1][choice2] != '-')
		{
			cpu(board);
		}
		else
		{
			return board[choice1][choice2] = 'O';
		}
	}
}