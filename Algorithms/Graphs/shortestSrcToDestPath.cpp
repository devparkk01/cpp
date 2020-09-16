/*Given a N X M matrix (M) filled with 1, 0, 2, 3. find whether there is path from src to dest
and if there is path, print the minimum no of steps needed to reach it while traversing
through blank cells only , else print -1 if the destination is not reachable. 
You may move in only four direction ie up, down, left and right. 

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.

This problem is similar to findWhetherPathExist from source to destination in a grid . 

The idea is to do bfs traversal . 
time : O(n*m)
*/

#include<bits/stdc++.h>
using namespace std;

struct cell {
	int x; int y ; int dist ; 
};

bool isSafe(int x ,int y, int n, int m ) {
    if( x < 0 || x >= n || y < 0 || y >= m ) 
        return false ; 
    return true ; 
}

int shortestPath(vector<vector<int>>&grid , int n , int m , int i,int j  ) {
	vector<vector<bool>>visited(n , vector<bool>(m)) ; 
	queue<cell>q ; 
	q.push({i , j , 0 }) ; 
	visited[i][j] = true; 

	int x, y,dist ; 
	while (!q.empty() ) {
		x = q.front().x ; y = q.front().y ; dist = q.front().dist ; 
		q.pop() ; 
		if (grid[x][y] == 2){
			return dist ; 
		}
		if(isSafe(x,y-1, n , m ) && !visited[x][y-1] && grid[x][y-1] != 0 ) {
			q.push({x , y-1 , dist+1}) ;
			visited[x][y-1] =true ; 
		}
		if(isSafe(x,y+1, n , m ) && !visited[x][y+1] && grid[x][y+1]!= 0 ) {
			q.push({x , y+1 , dist+1}) ; 
			visited[x][y+1] = true;  
		}
		if (isSafe(x-1,y ,n,m )&&!visited[x-1][y] && grid[x-1][y] != 0 ) {
			q.push({x-1 , y , dist+1}) ;
			visited[x-1][y] = true ; 
		}
		if (isSafe(x+1 , y , n , m) && !visited[x+1][y] && grid[x+1][y]!= 0 ) {
			q.push({x+1 , y ,dist + 1 }) ; 
			visited[x+1][y] = true ; 
		}
	}
	return -1 ; 


}



signed main () {
	int n , m ; 
	cin >> n >> m; 
	vector<vector<int>>grid(n , vector<int>(m)) ; 
	int x , y ;
	for(int i = 0 ;i < n ; ++i ) {
		for(int j = 0 ;j <m ;++j ) {
			cin >> grid[i][j] ; 
			if(grid[i][j] == 1 ) {
				x = i ; y = j ; 
			}
		}
	}
	cout << shortestPath(grid , n , m , x , y )  << endl; 
	return 0 ; 
}