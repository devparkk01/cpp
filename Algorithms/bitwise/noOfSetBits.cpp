/*
Given a positive integer N, print count of set bits in it.

It's called  Brian Kernighan’s Algorithm
*/

#include<bits/stdc++.h>
using namespace std ;

// time : O(no of set bits in N)
int setBits(int N) {
	if (N == 0 ) return 0 ;
	int c = 0 ; // stores the count of set bits
	while ( N != 0 ) {
		N = N & ( N - 1 ) ; // reduced 1 set bit from N
		c++  ;
	}
	return c ;
}

signed main() {
	int N = 13 ;
	cout << setBits(N) << endl;
	return 0 ;


}