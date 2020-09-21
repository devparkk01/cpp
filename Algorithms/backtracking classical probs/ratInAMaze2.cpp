// movement in all 4 directions are allowed . 


#include<bits/stdc++.h>
using namespace std ; 

void print(vector<vector<int>>&solution , int n ) {
	for(int i = 0 ; i < n  ; ++i ) {
		for(int j = 0 ;j < n ; ++j ) {
			cout << solution[i][j] <<" " ;
		}
		cout << endl ; 
	}
	cout << endl; 
}

bool safeMove(vector<vector<int>>&maze , int i , int j , int n ) {
	if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j] == 0 )
		return false ; 
	return true ; 
}


void solveMazeUtil(vector<vector<int>>&maze ,vector<vector<int>>&solution ,vector<vector<bool>>&visited ,int i ,int j ,int n ) {
	if ( safeMove(maze ,i , j , n ) && visited[i][j] == false ) {
		solution[i][j] = 1 ; 
		visited[i][j] = true ; 
		if (i == n-1 && j == n-1 ) {
			print(solution , n ) ;
			solution[i][j] = 0 ; 
			visited[i][j] = false ; 
			return  ; 
		}

		solveMazeUtil(maze , solution ,visited,  i +1 , j, n ) ;
		solveMazeUtil(maze , solution ,visited,  i , j-1 , n ) ;
		solveMazeUtil(maze , solution ,visited,  i , j+1, n ) ;
		solveMazeUtil(maze , solution ,visited,  i-1 , j , n ) ; 
		// backtracking 
		solution[i][j] = 0 ; 
		visited[i][j] = false ; 
	}
	else // backtracking 
		return ; 
}



void solveMaze(vector<vector<int>>&maze , int n ) {
	vector<vector<int>>solution(n , vector<int>(n)) ; 
	vector<vector<bool>>visited(n , vector<bool>(n)) ; 
	solveMazeUtil(maze , solution ,visited ,  0 , 0 , n ) ; 

}

signed main () {
	int n = 5 ; 
	vector<vector<int>>maze = { { 1, 0, 0, 0, 0 }, 
                        { 1, 1, 1, 1, 1 }, 
                        { 1, 1, 1, 0, 1 }, 
                        { 0, 0, 0, 0, 1 }, 
                        { 0, 0, 0, 0, 1 } } ;

    solveMaze(maze , n ) ; 
	return 0 ; 
}