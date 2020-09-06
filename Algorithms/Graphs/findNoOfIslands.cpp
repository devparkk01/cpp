/*
Given a Matrix consisting of 0s and 1s. Find the number of islands of connected 1s present 
in the matrix. 
Note: A 1 is said to be connected if it has another 1 around it (either of the 8 directions).
This is a variation of the standard problem: “Counting the number of connected components 
in an undirected graph”.
time : O(n*m) , space : O(n*m)
*/

	
#include<bits/stdc++.h>
using namespace std ; 


// N  is the row , M is the column 

void markCurrentIsland (vector<int> A[] , int x , int y , int N , int M) {
	// check for the boundary case of the matrix 
	if ( x < 0 || x >= N || y < 0 || y >= M || A[x][y] != 1 ) 
		return ; 
 	// mark current cell as visited 
	A[x][y] = 2 ; // can mark it as 0 also . 0 or 2 either works	
	markCurrentIsland(A , x-1 , y , N , M ) ;
	markCurrentIsland(A , x-1 , y+1 , N ,M ) ;
	markCurrentIsland(A , x-1 , y-1 , N , M ) ;
	markCurrentIsland(A , x , y+1 , N , M) ; 
	markCurrentIsland(A , x , y-1 , N , M ) ; 
	markCurrentIsland(A, x+1 , y , N , M ) ;
	markCurrentIsland(A , x+1 , y+1 , N , M ) ;
	markCurrentIsland(A , x+1 , y-1 , N , M ) ; 
}

int findIslands(vector<int> A[], int N, int M) {
	if ( N < 1 ) return 0 ; 

	int countIslands = 0 ; 
	// iterate for all cells of the array 
	for (int i = 0 ;i < N ; ++i ) {
		for(int j = 0 ; j < M ; ++j ) {
			if ( A[i][j] == 1) {
				markCurrentIsland(A , i , j , N , M ) ; 
				countIslands++ ; 
			}
		}
	}
	return countIslands ; 
}

signed main () {
	int N, M ; cin >> N >> M ; 
	vector<int>A[N] ;
	for( int i = 0 ;i < N ; ++i ) {
		A[i] = vector<int>(M) ; 
		for(int j = 0 ; j < M ; ++j ) {
			cin >> A[i][j] ; 
		}
	}
	cout << findIslands(A , N , M ) << endl; 

	return 0 ; 

}