#include<bits/stdc++.h>
using namespace std ; 
#define N 9 
#define unassigned 0 

// finds the unassigned location (cell) from the grid 
bool findUnassignedLocation(int grid[N][N] , int &row, int &col ) {
	for(int i = 0 ;i < 9 ; ++i ) {
		for (int j = 0 ; j < 9 ; ++j ) {
			if ( grid[i][j] == unassigned) {
				row = i ; col = j ; return true; 
			}
		}
	}
	return false ; 
}
// checks if num is already present in that row 
bool foundInRow(int grid[N][N] , int row ,int num ) {
	for(int col = 0 ; col < 9 ; ++col ) {
		if ( grid[row][col] == num)
			return true ; 
	}
	return false ; 
}
//checks if num is already present in that column
bool foundInColumn(int grid[N][N] , int col ,int num ) {
	for(int row= 0 ;row < 9 ; ++row ) {
		if ( grid[row][col] == num)
			return true ; 
	}
	return false ; 
}
// checks if num is already present in that box (subgrid)
bool foundInBox(int grid[N][N],int startRow , int startCol , int num ) {
	for(int row = 0 ; row < 3; ++row ) {
		for(int col = 0 ; col < 3 ; ++col ) {
			if ( grid[row + startRow][col + startCol] == num ) 
				return true ; 
		}
	}
	return false ; 
}
// checks if we can assign num to this cell or not 
bool isSafe(int grid[N][N],int row , int col , int num ) {
	if (foundInRow(grid,row,num)||foundInColumn(grid,col,num)||foundInBox(grid,row-row%3,col-col%3,num))
		return false ;	
	return true ;
}
// our main function 
bool solveSudoku(int grid[N][N] ) {
	int row , col ;
	if (findUnassignedLocation(grid,row,col)) {
		for(int num = 1 ; num <= 9 ; ++num ) {
			if(isSafe(grid ,row,col,num )){
				grid[row][col] = num ; // assign

				if (solveSudoku(grid)) // explore 
					return true ; 
				// unassign
				grid[row][col] = unassigned ; 
			}
		}
		// backtrack 
		return false ;  
	}
	else
		return true ; // no unassigned location means we're done

}
// prints the grid 
void printGrid(int grid[N][N]) {
	for(int i = 0 ; i < N; ++i ) {
		for(int j = 0 ; j < N; ++j ) {
			cout << grid[i][j] << " " ;
		}
		cout << endl; 
	}
}

signed main(){
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };


    if (solveSudoku(grid ) == true ) 
    	printGrid(grid ) ;
    else cout << "No solution exists "  ; 

    return 0 ;  
}