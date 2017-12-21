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

char cpuStrategy(char board[][3], int & counter)
{
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0;
	int same = 4, alsoSame = 4;
	int xRowCoord, yRowCoord, xColCoord, yColCoord, xDownRightDiagCoord, 
	    yDownRightDiagCoord, xUpLeftDiagCoord, yUpLeftDiagCoord;

	
	for(int i = 0; i<3; i++)
	{	
		for(int j = 0; j<3; j++)
		{
			//checking rows for two X's 
			if(board[i][j] == 'X')
			{
				cout << "." << endl;
				a++;
			}
			else if(board[i][j] == '-')
			{
				cout << "+" << endl;
				xRowCoord = i;
				yRowCoord = j;
			}
			else if(board[i][j] == 'O') //accounts for two X's and one O situation
			{
				cout << "-" << endl;
				b++;
			}
			
			//checks columns for two X's
			if(board[j][i] == 'X')
			{
				c++;
			}
			else if(board[j][i] == '-')
			{
				xColCoord = j;
				yColCoord = i;
			}
			else if(board[j][i] == 'O') //accounts for two X's and one O situation
			{
				d++;
			}
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
			{
				f++;
			}

			//checks up to the left
			int k = 2-j;
			if(board[k][j] == 'X' and k != alsoSame)
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
			{
				h++;
			}
		}
		if(a == 2 && b == 0)
		{
			cout << "row" << endl;
			cout << a << " " << b << endl;
			counter++;
			cout << "not random" << endl;
			cout << xRowCoord << " " << yRowCoord << endl;
			return board[xRowCoord][yRowCoord] = 'O';
			break;
		}
		if(c == 2 && d == 0)
		{
			cout << "column" << endl;
			cout << c << " " << d << endl;
			counter++;
			cout << xColCoord << " " << yColCoord << endl;
			return board[xColCoord][yColCoord] = 'O';
			break;
		}
		if(e == 2 && f == 0)
		{
			cout << "down right" << endl;
			cout << e << " " << f << endl;
			counter++;
			cout << "not random" << endl;
			cout << xDownRightDiagCoord << " " << yDownRightDiagCoord << endl;
			return board[xDownRightDiagCoord][yDownRightDiagCoord] = 'O';
			break;
		}
		if(g == 2 && h == 0)
		{
			cout << "up left" << endl;
			cout << g << " " << h << endl;
			counter++;
			cout << "not random" << endl;
			cout << xUpLeftDiagCoord << " " << yUpLeftDiagCoord << endl;
			return board[xUpLeftDiagCoord][yUpLeftDiagCoord] = 'O';
			break;
		}
		a = 0, b = 0, c = 0, d = 0;
		cout << endl;
		
	}

	

}

int main()
{
	int counter;
	char board[3][3] = {{'X','-','-'},{'X','X','-'},{'O','-','O'}};
	printboard(board);
	cpuStrategy(board, counter);
	printboard(board);
}