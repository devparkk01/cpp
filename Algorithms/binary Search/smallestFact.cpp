/*Given a number n. The task is to find the smallest number whose factorial contains
at least n trailing zeroes.

time : O(log2 N * log5 N)

*/

#include<bits/stdc++.h>
using namespace std ;

// returns number of zeros in a number n
int countZeros(int n ) {
	int count = 0 ;
	int divisor = 5 ;
	while ( n >= divisor ) {
		count += (n / divisor ) ;
		divisor *= 5 ;
	}
	return count ;
}

int smallestFact(int n ) {
	int low = 0 , high = n ;
	int mid , num , ans ;

	while ( low <= high ) {
		mid = low + (high - low ) / 2 ;
		num = 5 * mid ;
		int count = countZeros(num) ;
		if ( count == n ) return num ;
		else if ( count > n ) {
			ans = num ;
			high = mid - 1 ;
		}
		else if ( count < n ) low = mid + 1 ;
	}
	return ans ;
}


signed main () {
	int n = 3 ;
	cout << smallestFact(n) << endl;


	return 0 ;
}