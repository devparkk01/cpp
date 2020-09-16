/*Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
connected 8-directionally (horizontal or vertical or diagonal) You may assume all four edges of 
the grid  are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area 
is 0.)
Idea is based on the problem of finding number of islands in Boolean 2D-matrix
time : O(n *m ) 

*/


#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false ) ; cin.tie(NULL) ; 

void countRegion(vector<vector<int>> &graph , int x , int y , int n ,int m , int &count ) {
    if (x < 0 || x >= n || y < 0 || y >= m || graph[x][y] == 0 )
        return ; 
    graph[x][y] = 0 ; 
    count++ ; 
    countRegion(graph , x-1 , y , n , m , count ) ; 
    countRegion(graph , x-1 , y+1 , n , m , count ) ; 
    countRegion(graph , x-1 , y-1 , n , m , count ) ; 
    countRegion(graph , x , y-1 , n , m , count ) ; 
    countRegion(graph , x , y+1 , n , m , count ) ; 
    countRegion(graph , x+1 , y , n , m , count ) ; 
    countRegion(graph , x+1 , y+1 , n , m , count ) ; 
  	countRegion(graph , x+1 , y-1 , n , m , count ) ; 	
}

int main()
 {
	    int n , m  ; cin >> n >> m; 
	    vector<vector<int>>graph(n , vector<int>(m)) ; 
	    for(int i = 0 ;i < n; ++i ) {
	        for(int j = 0 ; j < m ; ++j ) {
	            cin >> graph[i][j] ; 
	        }
	    }
	    // running dfs 
	    int maxCount = 0 ; int count ; 
	    for(int i = 0 ; i < n ; ++i ) {
	        for(int j = 0 ;j < m ; ++j ) {
	           if (graph[i][j] == 1 ){
	               count = 0 ; 
	               countRegion(graph , i , j , n , m ,count ); 
	               maxCount = max(maxCount , count ) ; 
	           }
	        }
	    }
	    cout << maxCount << endl; 
	return 0;
}