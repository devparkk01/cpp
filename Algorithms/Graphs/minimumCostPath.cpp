/*Given a square grid of size N, each cell of which contains integer cost which represents a 
cost to traverse through that cell, we need to find a path from top left cell to bottom right
cell by which total cost incurred is minimum. You can move in 4 directions : up, down,
left and right.
Note : It is assumed that negative cost cycles do not exist in input matrix.

*/


#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 

struct cell {
    int x ; 
    int y ;
    int cost ; 
}; 

class compare 
{ 
public: 
  bool operator() (const cell &a, const cell &b)
  { 
    return (a.cost > b.cost); 
  } 
}; 
bool isSafe(int x ,int y ,int n ) {
    if ( x < 0 || x>=n || y < 0 || y >= n)
        return false ; 
    return true ; 
}

signed main()
{
    fastio ;
    int t ; cin >>t ; 
	while (t-- ) {
	    int n ; cin >> n ;
	    vector<vector<int>>grid(n , vector<int>(n))  ;
	    for(int i = 0 ;i < n; ++i ){
	        for(int j = 0 ; j <n ;++j ) {
	            cin >> grid[i][j] ; 
	        }
	    }
	    vector<vector<int>>dist(n , vector<int>(n ,INT_MAX ) ) ; 
	    dist[0][0] = grid[0][0] ; 
	    vector<vector<bool>>visited(n , vector<bool>(n));
	    priority_queue<cell , vector<cell> , compare > pq ; 
	    pq.push({0 , 0 , dist[0][0]}) ;
	    cell temp ; int x , y   ;
	    while (!pq.empty() ){
	        temp = pq.top() ; pq.pop() ; 
	        x = temp.x ; y = temp.y ; 
	        if (visited[x][y]) continue ; 
	        visited[x][y] = true; 
	  
	        if (isSafe(x-1 , y , n ) && !visited[x-1][y] && dist[x-1][y] > dist[x][y] + grid[x-1][y] ) {
	            dist[x-1][y] = dist[x][y] + grid[x-1][y] ; 
	            pq.push({x-1 , y , dist[x-1][y]}) ; 
	        }
	        if (isSafe(x+1 , y , n ) && !visited[x+1][y] && dist[x+1][y] > dist[x][y] + grid[x+1][y] ) {
	            dist[x+1][y] = dist[x][y] + grid[x+1][y] ; 
	            pq.push({x+1 , y , dist[x+1][y]}) ; 
	        }
	        if (isSafe(x , y-1 , n ) && !visited[x][y-1] && dist[x][y-1] > dist[x][y] + grid[x][y-1] ) {
	            dist[x][y-1] = dist[x][y] + grid[x][y-1] ; 
	            pq.push({x , y-1 , dist[x][y-1]}) ; 
	        }
	        if (isSafe(x , y+1 , n ) && !visited[x][y+1] && dist[x][y+1] > dist[x][y] + grid[x][y+1] ) {
	            dist[x][y+1] = dist[x][y] + grid[x][y+1] ; 
	            pq.push({x , y+1 , dist[x][y+1]}) ; 
	        }
	    }
	    cout << dist[n-1][n-1] << endl; 
	    
	}
	return 0;
}