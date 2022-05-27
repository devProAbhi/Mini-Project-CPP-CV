// C++ to solve Sudoku problem

#include <bits/stdc++.h>
using namespace std;
 
//UNASSIGNED is used for empty
//cells in sudoku grid
#define UNASSIGNED 0
 
//N is used for the size of Sudoku grid.
//Size will be NxN
#define N 9
 
//This function finds an entry in grid
//that is still unassigned

bool findEmptyPlace(int grid[N][N],int& row,int& col);
 
//Checks whether it will be legal
//to assign num to the given row, col

bool isValidPlace(int grid[N][N],int row,int col,int num);
 
/*Takes a partially filled-in grid and attempts 
to assign values to all unassigned locations in 
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes)*/

bool SolveSudoku(int grid[N][N])
{
    int row,col;
    //If there is no unassigned location,
    //we are done
    
    if(!findEmptyPlace(grid,row,col)) 
    //success!
    return true;

    // Consider digits 1 to 9

    for(int num=1;num<=9;num++) 

    {
        //Check if looks promising
    if(isValidPlace(grid,row,col,num)){
        //Make tentative assignment
        grid[row][col]=num;
        //Return, if success

            if(SolveSudoku(grid))
                return true;
 

            //Failure, unmake & try again

            grid[row][col]=UNASSIGNED;
        }

    }

    

    //This triggers backtracking

    return false;
}
 
/*Searches the grid to find an entry that is 
still unassigned. If found, the reference 
parameters row, col will be set the location 
that is unassigned, and true is returned. 
If no unassigned entries remain, false is returned.*/

bool findEmptyPlace(int grid[N][N],int& row,int& col)
{
    for(row=0;row<N;row++)
        for(col=0;col<N;col++)
            if(grid[row][col]==UNASSIGNED)
                return true;
    return false;
}
 
/*Returns a boolean which indicates whether 
an assigned entry in the specified row matches
the given number.*/

bool PresentInRow(int grid[N][N],int row,int num)
{
    for(int col=0;col<N;col++)
        if(grid[row][col]==num)
            return true;
    return false;
}
 
/*Returns a boolean which indicates whether 
an assigned entry in the specified column
matches the given number.*/

bool PresentInCol(int grid[N][N],int col,int num)
{

    for(int row=0;row<N;row++)
        if(grid[row][col]==num)
            return true;
    return false;
}
 
/*Returns a boolean which indicates whether 
an assigned entry within the specified 3x3 box 
matches the given number.*/

bool PresentInBox(int grid[N][N],int boxStartRow,int boxStartCol,int num)
{

    for (int row=0;row<3;row++)
        for (int col=0;col<3;col++)
            if (grid[row+boxStartRow]
                    [col+boxStartCol]==num)
                return true;
    return false;
}
 
/*Returns a boolean which indicates whether 
it will be legal to assign num to the given 
row, col location.*/

bool isValidPlace(int grid[N][N],int row,int col,int num)
{

    /*Check if 'num' is not already placed in 
    current row, current column and current 3x3 box*/

    return !PresentInRow(grid,row,num)&&!PresentInCol(grid,col,num)&&!PresentInBox(grid,row-row%3,col-col%3,num)&&grid[row][col]==UNASSIGNED;
}
 
/*A utility function to print grid*/

void printSudoku(int grid[N][N])
{    
    //print the sudoku grid after solve
    
   for(int row=0;row<N;row++) 
   {
      cout<<"[ ";
      for(int col=0;col<N;col++) 
      {
         cout<<grid[row][col]<<" ";
      }
      cout<<"]"<<endl;
      }
      cout<<endl;
}

//Driver Code

int main()
{

    //0 means unassigned cells
    
    //here is a demo sudoku, which we will solve

    int demo_sudoku[N][N]={{ 3, 0, 6, 5, 0, 8, 4, 0, 0 },
    { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
    { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
    { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
    { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
    { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
    { 0, 0, 5, 2, 0, 6, 3, 0, 0 }};
    
    //As input having 81 integers, so we are just running our demo_sudoku which input is itself in the code
    
    /*int sudoku[N][N];
    for(int i=0;i<N;++i)
    {
        for(int j=0;j<N;++j)
        {
            cin>>sudoku[i][j];
        }
    }

    if(SolveSudoku(sudoku)==true)
        printSudoku(sudoku);
    else
        cout<<"No solution exists";
    return 0;*/
    
    
    if (SolveSudoku(demo_sudoku)==true)
        printSudoku(demo_sudoku);
    else
        cout<<"No solution exists";
    return 0;
}
