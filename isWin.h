#include <iostream>
using namespace std;

bool isWin(char board[][3]) //checks if game is over
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	int same = 4, alsoSame = 4, anotherSame = 4, yetAnotherSame = 4;
	
	for(int i = 0; i<3; i++)
	{	
		for(int j = 0; j<3; j++)
		{
			//checking rows 
			if(board[i][j] == 'X')
			{	a++;	}
			else if(board[i][j] == 'O')
			{	b++;	}
			
			//checks columns
			if(board[j][i] == 'X')
			{	c++; 	}
			else if(board[j][i] == 'O')
			{	d++;	}
			//checks diagonals
			//checks down to the right
			if(board[j][j] == 'X' && j != same) 
			{	
				same = j;
				e++;
			}
			else if(board[j][j] == 'O' && j != anotherSame)
			{	
				anotherSame = j;
				f++;
			}

			//checks up to the left
			int k = 2-j;
			if(board[k][j] == 'X' and k != alsoSame)
			{
				alsoSame = k;
				g++;
			}
			else if(board[k][j] == 'O' && k != yetAnotherSame)
			{	
				yetAnotherSame = k;
				h++;
			}
		}
		if(a == 3)
		{ 	cout << "            You win!" << endl; return true; 	break;	}
		else if(b == 3)
		{ 	cout << "            You lose" << endl; return true; 	break;	}
		
		if(c == 3)
		{ 	cout << "            You win!" << endl; return true; 	break;	}
		else if (d == 3)
		{ 	cout << "            You lose" << endl; return true; 	break;	}
		
		if(e == 3)
		{ 	cout << "            You win!" << endl; return true; 	break;	}
		else if(f == 3)
		{ 	cout << "            You lose" << endl; return true; 	break;	}
		
		if(g == 3)
		{ 	cout << "            You win!" << endl; return true; 	break;	}
		else if (h == 3)
		{ 	cout << "            You lose" << endl; return true; 	break;	}
		
		a = 0, b = 0, c = 0, d = 0;
	}
	
	//checks for cat's game
	for(int i = 0; i<3; i++)
	{
		for(int j = 0; j<3; j++)
		{
			if(board[i][j] == '-')
			{
				return false;
			}
		}
	}
	cout << "     Cat's game: it's a tie!\n\n";
	return true;
}