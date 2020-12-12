/* Given an array of intergers ,find the maximum sum of subsequence of given array where
subsequence contains no adjacent elements

*/

#include<bits/stdc++.h>
using namespace std ;

// time : O(n) , space : O(n)
int maxSumNoAdj(int a[] , int n ) {
	if (n == 1 ) return a[0] ;
	if ( n == 2 ) return max(a[0] , a[1]) ;

	int dp[n] ;// dp[i] stores the max sum that can be obtained till ith index
	dp[0] = a[0] ; dp[1] = max(a[0] , a[1]) ;
	for (int i = 2 ; i < n; ++i ) {
		dp[i] = max({dp[i - 2] + a[i] , a[i] , dp[i - 1 ]}) ;
	}
	return dp[n - 1 ] ;
}


signed main () {
	int a[] = {2 , 3 , -1 , -2 , 5 , 3 } ;
	int n  = sizeof(a) / sizeof(int ) ;
	cout << maxSumNoAdj(a , n ) << endl;

	return 0 ;
}