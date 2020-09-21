/* The n queen is the problem of placing N chess queens on an N*N chessboard  so that 
no two queens attack each other . 

iterative approach
*/


#include<bits/stdc++.h>
#define endl '\n'
using namespace std ; 

void print(vector<int>&placements ) {
	cout << "[" ; 
	for(int &x : placements )
		cout << x+1 << " " ; 
	cout << "] "  ; 
}


bool safeMove(vector<int>&placements , int r , int c ) {
	for(int i = 0 ;  i < r ; ++i ) {
		if (placements[i] == c || abs(i -r ) == abs(placements[i] - c ) ) 
			return false ; 
	}
	return true ; 
}

void nqueens(int n ) {
	if ( n == 2 || n == 3 ) cout << -1  ; 
	vector<int>placements ; placements.reserve(n) ; 
	int r = 0 ; int c = 0 ; 
	while ( true ) {
		while (c < n ) {
			if ( safeMove(placements , r , c )) {
				placements.push_back(c) ; 
				if (r == n-1 ) {
					print(placements) ; 
					c++ ; placements.pop_back() ;
				}
				else {
					r++ ; c = 0 ; 
				}
			}
			else 
				c++ ; 
		}
		// backtracking step 
		if (placements.empty())  break ; 
		else {
			r-- ; 
			c = placements.back() ;  placements.pop_back() ; 
			c++ ; 
		}

	}
}

signed main () {
	int n ; cin >> n ; 
	nqueens(n) ; 
	cout << endl ; 

	return 0 ; 
}