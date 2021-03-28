/*
Given a positive integer N, print count of set bits in it.


It's called  Brian Kernighan’s Algorithm
*/


int setBits(int N) {
	if (N == 0 ) return 0 ;
	int c = 0 ;
	while ( N != 0 ) {
		N = N & ( N - 1 ) ;
		c++  ;
	}
	return c ;
}