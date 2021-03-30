/*
Given an array of n unique integers where each element in the array is in range [1, n].
The array has all distinct elements and size of array is (n-2).
Hence Two numbers from the range are missing from this array. Find the two missing numbers.

*/


#include<bits/stdc++.h>
using namespace std ;


void solve(int a[] , int n ) {
	int res = 0 ; int high = n + 2 ;

	for (int i = 0 ; i < n ; ++i ) res = res ^ a[i] ;

	for (int i = 1  ; i <= high ; ++i ) res = res ^ i ;

	// now I've got the xor value of two missing numbers
	int k = 1 ;
	while ( (res & 1) != 1 ) {
		k++ ;
		res = res >> 1 ;
	}

	int x = 0 , y = 0 ; //x =  first missing value , y = second missing value

	for (int i = 0 ; i < n ; ++i ) {
		if ( a[i] & (1 << (k - 1 ))) { // if kth bit of a[i] is set(1)
			x = x ^ a[i] ;
		}
		else y = y ^ a[i] ; // if kth bit is not set
	}

	for (int i = 1 ; i <= high ; ++i ) {
		if ( i & ( 1 << (k - 1 ))) { // if kth bit of i is set(1)
			x = x ^ i ;
		}
		else y = y ^ i ;
	}
	cout << x << " " << y << endl ;
}

signed main() {
	int a[] = {2 , 3 , 1, 6 , 8, 4} ;
	int n = sizeof(a) / sizeof(int) ;
	solve(a , n )  ;

	return 0 ;


}