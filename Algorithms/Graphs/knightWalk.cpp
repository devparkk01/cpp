/*Given a chess board of order N x M and source points (s1, s2) and destination points (d1, d2). 
The task to find minimum number of moves required by the Knight to go to the destination cell.

we will use bfs to solve this problem . 
time : O(n*n) , space  : O(n*n)

*/


#include<bits/stdc++.h>
using namespace std;
#define N 25

struct cell {
    int x, y , dist ; 
    cell(int x ,int y , int dist ) {
        this->x = x ; this->y  = y ; 
        this->dist = dist ; 
    }
}; 

bool isSafe(bool grid[N][N] , int n , int m , int i , int j ) {
    if ( i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1 ) 
        return false;  
    return true ; 
}

int walk(bool grid[N][N],int n , int m , int s1 , int s2 , int d1 , int d2 ) {
    queue<cell>q ; 
    q.push({s1 , s2 , 0}) ;
    grid[s1][s2] = 1 ; 
    int i,j,dist  ; 
    while (!q.empty()) {
        i = q.front().x ; j = q.front().y ; dist = q.front().dist ; 
        q.pop() ; 
        if (i == d1 && j == d2) {
            return dist ; 
        }
        if (isSafe(grid ,n , m , i+1 , j+2 )) {
            q.push(cell(i+1 , j+2, dist+ 1 )) ; 
            grid[i+1][j+2] = 1 ; 
        }if (isSafe(grid ,n , m , i-1 , j+2 )) {
            q.push(cell(i-1 , j+2 , dist+ 1 )) ; 
            grid[i-1][j+2] = 1 ; 
        }if (isSafe(grid ,n , m , i+2 , j-1 )) {
            q.push(cell(i+2,j-1,dist+ 1 )) ; 
            grid[i+2][j-1] = 1 ; 
        }if (isSafe(grid ,n , m , i+2 , j+1 )) {
            q.push(cell( i+2,j+1,dist+ 1 )) ; 
            grid[i+2][j+1] = 1 ; 
        }if (isSafe(grid ,n , m , i-1 , j-2 )) {
            q.push(cell(i-1 , j-2 , dist+ 1 )) ; 
            grid[i-1][j-2] = 1 ; 
        }if (isSafe(grid ,n , m , i+1 , j-2 )) {
            q.push(cell(i+1 , j-2 , dist+ 1 )) ; 
            grid[i+1][j-2] = 1 ; 
        }if (isSafe(grid ,n , m , i-2 , j+1 )) {
            q.push(cell(i-2 , j+1 , dist+ 1 )) ; 
            grid[i-2][j+1] = 1 ; 
        }if (isSafe(grid ,n , m , i-2 , j-1 )) {
            q.push(cell(i-2 , j-1, dist+ 1 )) ; 
            grid[i-2][j-1] = 1 ; 
        }
        
    }
    return -1 ; 
}

int main()
{
    int t;  cin >> t; 
    while (t-- ) {
        bool grid[N][N] ; 
        memset(grid , 0 , sizeof(grid)) ; 
        int n , m ; cin>> n >> m ; 
        int s1 , s2 , d1, d2 ; 
        cin >> s1 >> s2 >> d1 >> d2  ; 
        cout << walk( grid ,n , m , s1-1 , s2-1 , d1-1 , d2-1 ) << endl ; 
       
    }
	return 0;
}