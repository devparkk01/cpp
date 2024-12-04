/*
Given an array of n unique integers where each element in the array is in range [1, n].
The array has all distinct elements and size of array is (n-2).
Hence Two numbers from the range are missing from this array. Find the two missing numbers.

*/


#include<bits/stdc++.h>
using namespace std ;

// n is the range here , not the size of the array
// time  : O(n )
void solve(int a[] , int n ) {
	int res = 0 ; int len = n - 2 ;// len stores the length of the array a[]
	// take xor of all elements of the array
	for (int i = 0 ; i < len ; ++i ) res = res ^ a[i] ;
	// take xor of all elements in the range [1, n ]
	for (int i = 1  ; i <= n ; ++i ) res = res ^ i ;

	// now I've got the xor value of two missing numbers

	// find the position of rightmost set bit .k stores the position of rightmost set bit
	int k = 1 ;
	while ( (res & 1) != 1 ) {
		k++ ;
		res = res >> 1 ;
	}

	int x = 0 , y = 0 ; //x =  first missing value , y = second missing value

	for (int i = 0 ; i < len ; ++i ) {
		if ( a[i] & (1 << (k - 1 ))) { // if kth bit of a[i] is set(1)
			x = x ^ a[i] ;
		}
		else y = y ^ a[i] ; // if kth bit is not set
	}

	for (int i = 1 ; i <= n ; ++i ) {
		if ( i & ( 1 << (k - 1 ))) { // if kth bit of i is set(1)
			x = x ^ i ;
		}
		else y = y ^ i ; // if kth bit of i is not set
	}
	cout << x << " " << y << endl ;
}

signed main() {
	int a[] = {2 , 3 , 1, 6 , 7, 4} ;
	int len = sizeof(a) / sizeof(int) ;
	solve(a , len + 2 )  ;
	return 0 ;
}