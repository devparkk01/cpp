/*
Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path 
possible from source to destination, while traversing through blank cells only. You can traverse 
up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
Note: there is only single source and single destination.

input : 
4
3 0 0 0 
0 3 3 0 
0 1 0 3 
0 2 3 3 
output : 
1
input : 
3
0 3 2 
3 0 0
1 0 0
output : 
0
time : (n*n )

The idea is to breadth first search . 
*/


#include<bits/stdc++.h>
using namespace std;

bool isSafe(int x ,int y, int n ) {
    if( x < 0 || x >= n || y < 0 || y >= n ) 
        return false ; 
    return true ; 
}

bool checkPath(vector<vector<int>>&grid , int n, int i, int j ) {
    vector<vector<bool>>visited(n , vector<bool>(n)) ;
    queue<pair<int,int>>q ; 
    q.push({i, j}) ; 
    visited[i][j] = true ; int x ,y ; 
    while (!q.empty() ) {
        x = q.front().first ; y = q.front().second ; 
        q.pop() ;
        if ( grid[x][y] == 2) return true ; 
            
        if( isSafe(x-1,y,n ) && visited[x-1][y]== false && grid[x-1][y]!= 0 ) {
            q.push({x-1 , y}) ; 
            visited[x-1][y] = true ; 
        }if( isSafe(x+1,y,n ) && visited[x+1][y]== false && grid[x+1][y]!= 0 ) {
            q.push({x+1 , y}) ; 
            visited[x+1][y] = true ; 
        }if( isSafe(x,y+1,n ) && visited[x][y+1]== false && grid[x][y+1]!= 0 ) {
            q.push({x , y+1}) ; 
            visited[x][y+1] = true ; 
        }if( isSafe(x,y-1,n ) && visited[x][y-1]== false && grid[x][y-1]!= 0 ) {
            q.push({x , y-1}) ; 
            visited[x][y-1] = true ; 
        }
    }
    return false ; 
}


signed main()
 {
	//code
    int n ; cin >> n; 
    int x , y ;
    vector<vector<int>>grid(n , vector<int>(n)) ; 
    for(int i = 0 ;i < n; ++i ) {
        for(int j = 0 ; j < n; ++j  ) {
            cin >> grid[i][j] ;
            if (grid[i][j] == 1) {
                x = i ; y = j ; 
            }
        }
    }
    cout << checkPath(grid , n , x , y ) << endl;
	   
	return 0;
}