/*Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

*/

#include<bits/stdc++.h>
using namespace std ;

/*count the number of set bits in n , if it is equal to 1 , then n is a power of 2
	time : O(1 )
*/
bool isPowerOfTwo(int n ) {
	if ( n <= 0 ) return false ; // negative numbers or 0 can't be power of 2
	n = n & (n - 1 ) ; // removing 1 set bit from n
	if ( n == 0 ) return true ;
	else return false ;
}

signed main() {
	int n = 17;
	cout << isPowerOfTwo(n ) << endl ;
	return 0 ;

}