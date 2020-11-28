/*Given an array that represents elements of arithmetic progression in order. One element is
missing in the progression, find the missing number.

It is given that there will be a missing value for sure .

arr[]  = {2, 4, 8, 10, 12, 14}
Output: 6
arr[]  = {1, 6, 11, 16, 21, 31};
Output: 26

*/

#include<bits/stdc++.h>
using namespace std ;

// time : O(log n )
int binarySearch(int a[] , int n , int diff ) {
	int low = 0 ; int high = n - 1 ;
	int mid ;
	int expected ;

	while (low <= high ) {
		mid = low + (high - low ) / 2 ;
		if (a[mid + 1] - a[mid] != diff ) return a[mid] + diff ;

		expected = a[0] + mid * diff ;
		if ( expected == a[mid]) low = mid + 1 ;
		else if (expected != a[mid]) high = mid - 1 ;
	}
	return -1 ;
}


int findMissing(int a[] , int n ) {
	int diff = (a[n - 1] - a[0] ) / n ;
	return binarySearch(a, n , diff ) ;
}


signed main () {
	// int a[]  = {1, 6, 11, 16, 21, 31};
	int a[]  = { 2, 4, 8, 10, 12, 14} ;
	int n  = sizeof(a) / sizeof(int) ;
	cout << findMissing(a , n ) << endl;

	return 0 ;
}

