/*Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the 
integer part of the result is returned.
*/

#include<iostream>
using namespace std ; 

int mySqrtUtil(int n , int low , int high ) {
	if ( low == high ) {
		return low -1 ; 
	}
	int mid = low + (high - low) / 2 ; 
	if ( mid * mid == n ) return mid ; 
	if (mid * mid < n ) return mySqrtUtil(n , mid + 1 , high) ; 
	else return mySqrtUtil(n , low , mid - 1 ) ; 
}

int mySqrt(int n ) {
	int low = 0 ; int high = n ; 
	return mySqrtUtil(n , low , high ) ; 
}

signed main () {
	int n = 12 ; 
	cout << mySqrt(n) << endl; 

	return 0 ; 
}