/* NxN SUDOKU SOLVER 

  Authour: Sai Praneeth (1031310381)
           Satyam Verma (1031310411)
 

*/

#include<iostream>
#include<cmath>

using namespace std;

#define N 9						//Can be changed to change the matrix size
#define	rtN 3					//Changes are needed to be made here also
#define UNASSIGNED 0

bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num);

/* Take input from user */
void getGrid(int grid[N][N]){
	int i,j;
	
	cout<<"Enter an unsolved Sudoku in the form of a 9x9 matrix, with 0s in the place of unfilled locations.\n\n";
	
	for(i = 0; i<N;i++){
		for(j=0;j<N;j++){
			cin>>grid[i][j];
		}
	}
}

/* assign values to all unassigned locations for Sudoku solution  */ 
bool SolveSudoku(int grid[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(grid, row, col))
       return true;
    for (int num = 1; num <= N; num++)
    {
	    if (isSafe(grid, row, col, num))
	    {
	        grid[row][col] = num;
	        if (SolveSudoku(grid))
	            return true;
	        grid[row][col] = UNASSIGNED;
	    }
    }
    return false;
}

/* Searches the grid to find an entry that is still unassigned. */
bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == UNASSIGNED)
                return true;
    return false;
}

/* Returns whether any assigned entry n the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
    if (grid[row][col] == num)
        return true;
    return false;
}

/* Returns whether any assigned entry in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

/* Returns whether any assigned entry within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < rtN; row++)
        for (int col = 0; col < rtN; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

/* Returns whether it will be legal to assign num to the given row,col location. */
bool isSafe(int grid[N][N], int row, int col, int num)
{
    return !UsedInRow(grid, row, num) && !UsedInCol(grid, col, num) &&
       !UsedInBox(grid, row - row % rtN , col - col % rtN, num);
}


/* To print the grid */
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++){
            cout<<grid[row][col]<<"  ";
            if((col+1)%rtN == 0)	cout<<"  ";
        }
        if((row+1)%rtN == 0)	cout<<endl;
        cout<<endl;
    }
}

/* Driver program */
int main()
{
	int grid[N][N];

	getGrid(grid);
					
    if (SolveSudoku(grid) == true){
    	cout<<"\nSolution:\n\n";
        printGrid(grid);
    }
    else
        cout<<"No solution exists"<<endl;
    return 0;

}

/*   Test Case     */
/*

5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

*/
