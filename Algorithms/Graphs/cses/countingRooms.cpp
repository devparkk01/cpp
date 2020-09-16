#include<bits/stdc++.h>
using namespace std ; 
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 



void markCurrentRoom(vector<vector<char>> &graph ,int x, int y , int r , int c  ) {
	if (x < 0 || x >= r || y < 0 || y>= c || graph[x][y] == '#') 
		return ;
	graph[x][y] = '#' ;

	markCurrentRoom(graph , x-1 , y , r ,c ) ;
	markCurrentRoom(graph , x+1 , y , r , c );
	markCurrentRoom(graph , x , y+1 , r , c) ;
	markCurrentRoom(graph , x , y-1 , r , c ) ;

}

void print(vector<vector<char>> &graph , int r , int c ) {
	for(int i = 0 ; i < r ; ++i ) {
		for(int j = 0 ; j < c ; ++j ) {
			cout << graph[i][j]  ;
		}
		cout << endl ; 
	}
}

signed main () {
	if( isSafe(x-1,y,n , m ) && visited[x-1][y]== false && grid[x-1][y]!= 0 ) {
            dfs(grid , visited , x-1 , y , i , j ,count+1 , found , n , m ) 
    }
    if( isSafe(x+1,y,n , m ) && visited[x+1][y]== false && grid[x+1][y]!= 0 ) {
            dfs(grid , visited , x+1 , y , i , j ,count+1 , found , n , m ) 
    }
    if( isSafe(x,y+1,n , m ) && visited[x][y+1]== false && grid[x][y+1]!= 0 ) {
            dfs(grid , visited , x , y+1 , i , j ,count+1 , found , n , m ) 
    }
    if( isSafe(x,y-1,n , m ) && visited[x][y-1]== false && grid[x][y-1]!= 0 ) {
            dfs(grid , visited , x , y-1 , i , j ,count+1 , found , n , m ) 
    }
	return 0 ; 

}


