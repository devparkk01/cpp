/*Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the 
integer part of the result is returned.
*/

#include<iostream>
using namespace std ; 

int mySqrt(int n ) {
	if ( n == 0 || n == 1 ) return n ; 
	int low = 0 ; int high = n/2 ; 
	int ans ;
	while ( low <= high ) {
		int mid = low + (high - low )/2 ; 
		if ( mid * mid == n ) return mid ; 
		else if ( mid * mid < n ) {
			ans = mid ; 
			low = mid + 1 ; 
		}
		else if (mid * mid > n ) {
			high = mid - 1; 
		}
	}
	return ans ; 
}


signed main () {
	int n = 102 ; 
	cout << mySqrt(n) << endl; 

	return 0 ; 
}