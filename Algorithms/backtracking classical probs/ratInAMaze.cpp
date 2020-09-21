// movement in only 2 directions(right , down ) are allowed .
// time : O(2 ^ (n ^ n)) 

#include<bits/stdc++.h>
using namespace std ; 

void print(vector<vector<int>>&solution , int n ) {
	for(int i = 0 ; i < n  ; ++i ) {
		for(int j = 0 ;j < n ; ++j ) {
			cout << solution[i][j] <<" " ;
		}
		cout << endl; 
	}
}

bool safeMove(vector<vector<int>>&maze , int i , int j , int n ) {
	if (i < 0 || i >= n || j < 0 || j >= n || maze[i][j]  == 0 )
		return false ; 
	return true ; 
}

void solveMazeUtil(vector<vector<int>>&maze , vector<vector<int>>&solution , int i ,int j ,int n ) {
	if ( safeMove(maze ,i , j , n )) {
		solution[i][j] = 1 ; 
		if (i == n-1 && j == n-1 ) {
			print(solution , n ) ; 
			//backtracking 
			solution[i][j] = 0 ; 
			return  ; 
		}
		solveMazeUtil(maze , solution , i , j+1, n ) ;
		solveMazeUtil(maze , solution , i +1 , j, n ) ;
		// backtracking 
		solution[i][j] = 0 ; 
	}
	else // backtracking 
		return ; 
}



void solveMaze(vector<vector<int>>&maze , int n ) {
	vector<vector<int>>solution(n , vector<int>(n)) ; 
	solveMazeUtil(maze , solution , 0 , 0 , n ) ; 

}

signed main () {
	int n = 3 ; 
	// vector<vector<int>>maze = {{ 1, 0, 0, 0 }, 
 //                       { 1, 1, 0, 1 }, 
 //                       { 0, 1, 0, 0 }, 
 //                       { 1, 1, 1, 1 }} ;
	// vector<vector<int>>maze = {
	// 	{1 ,1 , 1 } , {1 ,1 , 1 } , {1 , 1, 1 }
	// } ;
	vector<vector<int>>maze( n , vector<int>(n , 1 )) ; 
	maze[2][1] = 0 ; 

    // print(maze , n )  ;
    solveMaze(maze , n ) ; 
	return 0 ; 
}