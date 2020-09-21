/*Given a matrix of dimension n*m where each cell in the matrix can have values 0, 1 or 2 which
has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges

So, we have to determine what is the minimum time required to rot all oranges.
A rotten orange at index [i,j] can rot other fresh orange at indexes  [i-1,j], [i+1,j],
[i,j-1], [i,j+1] (up, down, left and right) in unit time. If it 
is impossible to rot every orange then simply return -1.

time : O(n * m )
*/
#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false ) ; cin.tie(NULL) ; 
using namespace std;

struct cell {
    int x , y ,  time ; 
    cell(int x, int y , int time ) {
        this->x = x ;
        this->y = y ;
        this->time = time ; 
    }
}; 

bool isSafe(vector<vector<int>>&grid , int i , int j , int n , int m ) {
    if ( i < 0|| i >= n ||j < 0 || j >= m || grid[i][j] != 1)
        return false ;
    return true ; 
}

int findRottenOranges(vector<vector<int>>&grid , int n , int m ) {
    queue<cell>q ; 
    for(int i = 0 ; i < n ; ++i ) {
        for(int j= 0 ; j < m; ++j ) {
            if(grid[i][j] == 2 )
                q.push(cell(i , j , 0 )) ; 
        }
    }
    int x, y , time ;
    while (!q.empty()) {
        x = q.front().x ; 
        y = q.front().y ; 
        time = q.front().time ; 
        q.pop() ; 
        if ( isSafe(grid , x+1 , y , n , m ) ) {
            grid[x+1][y] = 2 ; 
            q.push(cell(x+1 , y , time+1)) ;
        }
        if ( isSafe(grid , x-1 , y , n , m ) ) {
            grid[x-1][y] = 2 ;
            q.push(cell(x -1 , y , time+ 1 )) ;
        }
        if ( isSafe(grid , x , y-1 , n , m )) {
            grid[x][y-1] = 2 ; 
            q.push(cell(x , y-1 , time + 1 ))  ;
        }
        if ( isSafe(grid , x , y+1 , n , m )) {
            grid[x][y+1] = 2 ; 
            q.push(cell(x , y + 1,  time+ 1 )) ; 
        }
        
    }
    for(int i = 0 ; i < n ; ++i) {
        for(int j = 0 ; j < m; ++j ) {
            if ( grid[i][j] == 1 )
                return -1 ; 
        }
    }
    return time ; 
}

int main()
 {
	//code
	fastio ; 
	int t;  cin >> t; 
	while (t-- ) {
	    int n , m ; cin >> n >> m ; 
	    vector<vector<int>>grid(n , vector<int>(m)) ; 
	    for(int i = 0 ; i < n ; ++i ) {
	        for(int j= 0 ; j < m ; ++j )
	            cin >> grid[i][j] ; 
	    }
	    cout << findRottenOranges(grid , n , m ) << endl; 
	   
	}
	return 0;
}	