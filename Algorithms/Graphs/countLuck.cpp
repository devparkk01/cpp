/*  https://www.hackerrank.com/challenges/count-luck/problem

*/

// solving using bfs

#include<bits/stdc++.h>
using namespace std ;
#define vec vector
#define ip pair<int ,int>
struct cell {
	int r, c , w ;
} ;

bool inside(int r , int c , int n , int m ) {
	if ( r < 0 || r >= n || c < 0 || c >= m ) return false ;
	return true ;
}

int count (int r , int c , int n , int m ,  vec<vec<char>>&matrix ) {
	int x = 0 ;
	if (inside(r + 1 , c , n , m ) && (matrix[r + 1][c] == '.' || matrix[r + 1][c] == '*' ))  {
		x++  ;
	}
	if (inside(r - 1 , c , n , m ) && (matrix[r - 1 ][c] == '.' || matrix[r - 1 ][c] == '*' )) {
		x++  ;
	}
	if (inside(r , c + 1  , n , m ) && (matrix[r ][c + 1 ] == '.'  || matrix[r ][c + 1 ] == '*')) {
		x++  ;
	}
	if (inside(r , c - 1  , n , m ) && (matrix[r ][c - 1 ] == '.'  || matrix[r ][c - 1 ] == '*' )) {
		x++  ;
	}
	return x ;
}

signed main () {
	int t ; cin >> t;
	while (t-- ) {
		int n , m ; cin >> n >> m ;
		vec<vec<char>>matrix(n , vec<char>(m)) ;
		int r , c , dr , dc ;
		for (int i = 0 ; i < n ; ++i ) {
			for (int j = 0 ; j < m ; ++j ) {
				cin >> matrix[i][j] ;
				if ( matrix[i][j] == 'M') {
					r = i , c = j ;
				}
				else if ( matrix[i][j ] == '*') {
					dr = i ; dc  = j  ;
				}
			}
		}
		int k ; cin >> k ;
		queue<cell>q ; q.push({r , c , 0 }) ;
		cell temp ; int w ;
		while (!q.empty()) {
			temp = q.front() ; q.pop() ;
			r = temp.r ; c = temp.c ; w = temp.w ;
			if ( r == dr && c == dc ) break;
			int x = count(r , c , n , m , matrix ) ;
			if ( x == 1 ) x = 0 ;
			else if ( x > 1 ) x = 1 ;

			if (inside(r + 1 , c , n , m ) && (matrix[r + 1][c] == '.' || matrix[r + 1][c] == '*' ))  {
				q.push({r + 1 , c , w + x }) ;
				matrix[r + 1][c] = 'X' ;
			}
			if (inside(r - 1 , c , n , m ) && (matrix[r - 1 ][c] == '.' || matrix[r - 1 ][c] == '*' )) {
				q.push({r - 1 , c , w + x }) ;
				matrix[r - 1 ][c] = 'X' ;
			}
			if (inside(r , c + 1  , n , m ) && (matrix[r ][c + 1 ] == '.'  || matrix[r ][c + 1 ] == '*')) {
				q.push({r , c + 1 , w + x   }) ;
				matrix[r ][c + 1 ] = 'X' ;
			}
			if (inside(r , c - 1  , n , m ) && (matrix[r ][c - 1 ] == '.'  || matrix[r ][c - 1 ] == '*' )) {
				q.push({r , c - 1 , w + x  }) ;
				matrix[r ][c - 1 ] = 'X' ;
			}
		}
		if ( w == k ) cout << "Impressed" << endl ;
		else cout << "Oops!" << endl;

	}

	return 0 ;
}
















