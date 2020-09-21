/*Given a 2D screen, location of a pixel in the screen ie(x,y) and a color(K), your task
is to replace color of the given pixel and all adjacent(excluding diagonally adjacent)
same colored pixels with the given color K.
time : O(n*m)
*/

#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL ) ; 
#define endl '\n'

void print(vector<vector<int>>&grid ,int n , int m ) {
    for(int i = 0 ;i < n ; ++i ) {
        for(int j= 0 ; j < m ; ++j ) 
            cout << grid[i][j] << " " ; 
    }
    cout << endl; 
}

void dfs (vector<vector<int>>&grid , int n , int m , int x , int y , int s , int &k) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != s)
        return ;
    grid[x][y] = k ;
    dfs(grid , n , m , x-1 , y , s , k ) ;
    dfs(grid , n , m , x+1 , y , s , k ) ;
    dfs(grid , n , m , x , y-1 , s , k ) ;
    dfs(grid , n , m , x , y+1 , s , k ) ;
    
}

int main()
{
	fastio ; 
	int t; cin >> t; 
	while (t-- ) {
	    int n , m ;  cin >> n >> m ; 
	    vector<vector<int>>grid(n , vector<int>(m)) ; 
	    for(int i = 0 ; i < n ; ++i ) {
	        for(int j =0 ; j < m ; ++j ) {
	            cin >> grid[i][j];  
	        }
	    }
	    int x , y , k ; 
	    cin >> x >> y >> k ; 
	    
	    if (grid[x][y] != k) {
	        dfs(grid , n , m , x, y, grid[x][y] , k ) ; 
	    }
	    print(grid , n , m ) ; 
	}
	return 0;
}