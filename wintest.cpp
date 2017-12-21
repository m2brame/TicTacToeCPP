#include<iostream>
#include<cstdlib>
#include<ctime>
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

char cpuStrategy(char board[][3])
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
				e++; cout << "*";
			}
			else if(board[j][j] == 'O' && j!= anotherSame)
			{	
				anotherSame = j;
				f++; cout << "+" << endl;	}

			//checks up to the left
			int k = 2-j;
			if(board[k][j] == 'X' && k != alsoSame)
			{
				alsoSame = k;
				g++;
			}
			else if(board[k][j] == 'O' && k!= yetAnotherSame)
			{	yetAnotherSame = k; h++;	}
		}
		if(a == 3)
		{ 	cout << "You win!." << endl; 	break;	}
		else if(b == 3)
		{ 	cout << "You lose.." << endl; 	break;	}
		
		if(c == 3)
		{ 	cout << "You win!..." << endl; 	break;	}
		else if (d == 3)
		{ 	cout << "You lose...." << endl; 	break;	}
		
		if(e == 3)
		{ 	cout << ".You win!" << endl; 	break;	}
		else if(f == 3)
		{ 	cout << "..You lose" << endl; 	break;	}
		
		if(g == 3)
		{ 	cout << "...You win!" << endl; 	break;	}
		else if (h == 3)
		{ 	cout << "....You lose" << endl; 	break;	}
		
		a = 0, b = 0, c = 0, d = 0;
	}
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

int main()
{
	int counter;
	char board[3][3] = {{'O','X','O'},{'O','X','X'},{'X','-','O'}};
	printboard(board);
	cpuStrategy(board);
	printboard(board);
}