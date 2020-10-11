#include<stdio.h>
#include<time.h>

int n, x, y;

int knight(int x, int y, int movei, int board[n][n], int MoveX[], int MoveY[]);

int safe(int x, int y, int board[n][n])
{
	return(x>=0 && x<n && y>=0 && y<n && board[x][y]==-1);
}

void print_Board(int board[n][n])
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
		printf("%2d\t", board[i][j]);
		}
		printf("\n");
	}
}

int Knight_tour(int n, int x, int y)
{
	int board[n][n], i, j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			board[i][j]= -1;
		}
	}
	int MoveX[8]= {-2, -2, -1, -1, 1, 1, 2, 2};
	int MoveY[8]= {1, -1, 2, -2, 2, -2, 1, -1};
	board[x][y]=0;
	if((Knight(x, y, 1, board, MoveX, MoveY)==0))
	{
		printf("\nSolution does not exist");
		return 0;
	}
	else
	{
		print_Board(board);
	}
	return 1;
}

int Knight(int x, int y, int movei, int board[n][n], int MoveX[8], int MoveY[8])
{
	int k, nextX, nextY;
	if(movei==n * n)
	{
		return 1;
	}
	for(k=0; k<8; k++)
	{
		nextX= x + MoveX[k];
		nextY= y + MoveY[k];
		if(safe(nextX, nextY, board))
			{
				board[nextX][nextY]= movei;
				if(Knight(nextX, nextY, movei+1, board, MoveX, MoveY)==1)
				{
					return 1;
				}
				else
				{
					board[nextX][nextY]= -1;
				}
			}	
	}
	return 0;
}

int main()
{
	printf("\nEnter dimension of chessboard: ");
	scanf("%d", &n);
	printf("\nEnter the value of the x and y coordinate of the starting position of the knight:\n");
	scanf("%d %d", &x, &y);
	clock_t t;
	t = clock();
	Knight_tour(n, x, y);
	t=clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC; 
    printf("The function took %f seconds to execute \n", time_taken);
	return 0;
}

