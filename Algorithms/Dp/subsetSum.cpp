/*Given a set of non-negative integers ,and a value 'sum', determine if there is a subset of the 
given set with sum equal to given sum .
variation of 0-1 knapsack problem 
*/

/* Recursive solution */
#include<bits/stdc++.h>
using namespace std ; 

// Recursive approach  , time : O(2^n)

// bool subsetSum (int set[] , int n, int sum ) {
// 	if (sum == 0 ) return true ; 
// 	if (n == 0 ) return false ; 

// 	if (set[n-1] > sum ) 
// 		return subsetSum(set , n-1 , sum ) ; 
// 	bool include = subsetSum(set , n-1 , sum - set[n-1]) ; 
// 	bool exclude = subsetSum(set , n-1 , sum ) ; 
// 	return include || exclude ; 
// }

/* Top down approach , time : O(n * sum ) */

bool subsetSumUtil (int set[] , int n , int sum , int dp[101][101]) {
	if (sum == 0 ) return true ; 
	if (n == 0 ) return false ; 

	if (dp[n][sum] != -1 )  return dp[n][sum] ;

	if ( set[n-1] > sum )
		dp[n][sum] = subsetSumUtil(set , n-1 , sum , dp ) ; 
	else {
		int include = subsetSumUtil(set , n-1 , sum-set[n-1] , dp) ; 
		int exclude = subsetSumUtil(set ,n-1 , sum , dp) ; 
		dp[n][sum] = include || exclude ; 
	}
	return dp[n][sum] ; 
}

bool subsetSum (int set[] , int n , int sum ){
	int dp[101][101] ;
	memset(dp , -1 , sizeof(dp)) ; 
	return subsetSumUtil(set, n , sum , dp ) ; 
}

/* Bottom up approach */ 

// bool subsetSum (int set[] , int n, int sum ) {
// 	bool dp[n+1][sum+1] ;
// 	for(int j = 0 ; j <= sum ; ++j)
// 		dp[0][j] = false ; 
// 	for(int i = 0 ; i <= n ; ++i) 
// 		dp[i][0] = true ; 

// 	for(int i = 1 ; i <= n ; ++i ) {
// 		for(int j = 1 ; j <= sum ; ++j ) {
// 			if ( set[i-1] > j ) dp[i][j] = dp[i-1][j] ; 
// 			else 
// 				dp[i][j] = dp[i-1][j - set[i-1]] || dp[i-1][j] ; 	
// 		}
// 	}
// 	return dp[n][sum] ; 

// }

signed main(){
	int set[] = {3, 34, 4 ,12 , 5 ,2 } ;
	int n = sizeof(set)/sizeof(set[0]) ; 
	int sum = 20 ; 
	cout << subsetSum(set , n , sum) << endl; 
	return 0 ; 
}