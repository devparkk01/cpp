/*print the sorted array of strings denoting all the possible directions which the rat
can take to reach the destination 
*/

#include<bits/stdc++.h>
using namespace std ; 


void print(vector<string >&allPaths ) {
	for(string &x : allPaths) 
		cout << x << " " ;
	cout << endl; 
}

bool safeMove(vector<vector<int>>&maze,vector<vector<bool>>&visited,  int i , int j , int n  ) {
	if ( i < 0|| i >= n || j < 0 || j >= n || maze[i][j] == 0 || visited[i][j])
		return false ; 
	return true ; 
}

void solveMazeUtil(vector<vector<int>>&maze,string &curPath,vector<string>&allPaths , vector<vector<bool>>&visited ,int i , int j , int n ) {
		if (i == 0 && j == 0 && maze[i][j] != 1 ) return ; 

		visited[i][j] = true ; 
		if (i == n-1 && j == n-1 ) {
			allPaths.push_back(curPath) ;
			// backtracking 
			// curPath.pop_back() ;
			visited[i][j] = false ; 
			return ; 
		}
		if (safeMove(maze,visited, i+1 , j , n) ){
			curPath.push_back('D') ; 
			solveMazeUtil(maze , curPath , allPaths , visited , i+1 , j , n ) ;
			curPath.pop_back() ;

		}
		if (safeMove(maze,visited, i , j-1 , n ) ) {
			curPath.push_back('L') ;
			solveMazeUtil(maze , curPath , allPaths , visited , i , j-1 , n ) ;
			curPath.pop_back() ;

		}
		if (safeMove(maze,visited, i , j+1 , n ) ) {
			curPath.push_back('R') ;
			solveMazeUtil(maze , curPath , allPaths , visited , i , j+1 , n ) ;
			curPath.pop_back() ; 

		}
		if (safeMove(maze,visited, i-1 ,j,n)) {
			curPath.push_back('U') ;
			solveMazeUtil(maze , curPath , allPaths , visited , i-1 , j , n ) ;
			curPath.pop_back() ; 
		}
		// backtracking 		
		visited[i][j] = false ; 

}

void solveMaze(vector<vector<int>>&maze , int n ) {
	vector<vector<bool>>visited(n , vector<bool>(n)) ; 
	string curPath ; 
	vector<string>allPaths ; 
	solveMazeUtil(maze , curPath , allPaths , visited , 0 , 0 , n ) ; 
	print(allPaths) ;
}

signed main () {
	int n = 4 ; 
	vector<vector<int>>maze =  {{1, 0, 0, 0},
                       {1, 1, 0, 1}, 
                       {1, 1, 0, 0},
                       {0, 1, 1, 1}} ;


    solveMaze(maze , n ) ; 
	return 0 ; 
}