#include<bits/stdc++.h>
using namespace std ; 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL ) ; 
#define endl '\n' 

struct cell {
	int x ; int y ; int dist ; string path ; 
}; 

bool isSafe(int x , int y , int n , int m ) {
	if ( x < 0 || x >= n || y < 0 || y >= m )
		return false ;
	return true ; 
}

// i, j represents source vertex 
void bfs(vector<vector<char>>&grid , int  n , int m , int i , int j ) {
	vector<vector<bool>>visited( n , vector<bool>(m)) ; 
	queue<cell>q ; 
	q.push({i , j , 0 , ""}) ; 
	visited[i][j] = true ; 
	int x , y , dist ; string str; str.reserve(1000)  ; 
	while (!q.empty()) {
		x = q.front().x ; y = q.front().y ; dist = q.front().dist ;
		str = q.front().path ;
		q.pop(); 
		if ( grid[x][y] == 'B') {
			cout << "YES" << endl; 
			cout << dist << endl; 
			cout << str << endl; 
			return ; 
		}
		if(isSafe(x,y-1, n , m ) && !visited[x][y-1] && grid[x][y-1] != '#' ) {
			q.push({x , y-1 , dist+1 , str+'L' }) ;
			visited[x][y-1] =true ; 
		}
		if(isSafe(x,y+1, n , m ) && !visited[x][y+1] && grid[x][y+1]!= '#' ) {
			q.push({x , y+1 , dist+1, str+'R' }) ; 
			visited[x][y+1] = true;  
		}
		if (isSafe(x-1,y ,n,m )&&!visited[x-1][y] && grid[x-1][y] != '#' ) {
			q.push({x-1 , y , dist+1, str+'U'}) ;
			visited[x-1][y] = true ; 
		}
		if (isSafe(x+1 , y , n , m) && !visited[x+1][y] && grid[x+1][y]!= '#' ) {
			q.push({x+1 , y ,dist + 1 , str+'D' }) ; 
			visited[x+1][y] = true ; 
		}
	}
	cout << "NO" << endl; 
}




signed main () {
	fastio ; 
	int n, m ; cin >> n >> m  ;
	vector<vector<char>>grid(n , vector<char>(m)) ; 
	int x , y ; 
	for(int i = 0 ; i < n ; ++i ) {
		for(int j = 0 ; j < m ; ++j ) {
			cin >> grid[i][j] ; 
			if ( grid[i][j] == 'A') {
				x = i ; y = j ; 
			}
		}
	}
	// for(int i = 0 ; i< n; ++i ) {
	// 	for(int j = 0  ;j < m ; ++j ) {
	// 		cout << grid[i][j]  ;
	// 	}
	// 	cout << endl ; 
	// }
	bfs(grid , n , m , x , y ) ; 
	return 0 ; 
}


/*
5 8
########
##A#...#
#.##.#B#
#......#
########

*/
