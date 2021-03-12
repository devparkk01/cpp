/*Also called partition problem . The partition problem is to determine whether a given set
can be partitioned into two subsets such that the sum of elements in both subsets is the
same .
variation of subset Sum problem , which itself is a variation of 0-1 knapsack problem
*/

#include<bits/stdc++.h>
using namespace std ;

/* Recursive appraoch , time : O(2^n) */

bool equalPartitionUtil (int n , int arr[] , int sum ) {
	if ( sum == 0 ) return true ;
	if ( n == 0 ) return false ;

	if ( arr[n - 1] > sum )
		return equalPartitionUtil(n - 1 , arr , sum ) ;
	else {
		bool include = equalPartitionUtil(n - 1 , arr, sum - arr[n - 1]) ;
		bool exclude = equalPartitionUtil(n - 1 , arr , sum ) ;
		return include || exclude ;
	}
}

bool equalPartition(int n , int arr[]) {
	int sum = accumulate(arr, arr + n , 0) ;
	if ( sum & 1 ) return false ;
	sum = sum / 2 ;
	return equalPartitionUtil(n , arr , sum / 2 ) ;
}


// Bottom up appraoch , time : O(n * sum )

// bool equalPartition(int n, int arr[])
// {
//     int sum = accumulate(arr , arr+ n , 0) ;
//     if ( sum & 1 ) return false ;
//     sum = sum/2 ;
//     bool dp[n+1][sum+1] ;
//     for(int j = 0 ; j <= sum ; ++j ) dp[0][j] = 0 ;
//     for(int i = 0 ; i <= n ; ++i ) dp[i][0] = 1 ;

//     for (int i = 1 ; i <= n ; ++i ) {
//         for(int j =1 ; j <= sum ; ++j ) {
//             if ( arr[i-1] > j ) dp[i][j] = dp[i-1][j] ;
//             else
//                 dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j] ;
//         }
//     }
//     return dp[n][sum] ;
// }

signed main () {
	int arr[] = {3 , 4 , 2,  3} ;
	int n = sizeof(arr) / sizeof(int) ;
	cout << equalPartition(n , arr ) << endl;
	return 0 ;
}