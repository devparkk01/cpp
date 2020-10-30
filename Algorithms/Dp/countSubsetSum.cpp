/*Given a set contaning n elements , count the number of subsets of this set having sum
equal to a given sum .
variation of subset sum problem , variation of o-1 knapsack problem 

*/
#include<bits/stdc++.h>
using namespace std ; 

// recursive approach , time : O(2^n)

// int countSubsets(int set[] , int n, int sum ) {
// 	if (sum == 0) return 1 ; 
// 	if ( n == 0 ) return 0 ; 

// 	if ( set[n-1] > sum) 
// 		return countSubsets(set , n-1 , sum) ;
// 	else {
// 		int include = countSubsets(set ,n-1 , sum - set[n-1]); 
// 		int exclude = countSubsets(set , n-1 , sum) ; 
// 		return include + exclude ; 
// 	}
// }

// Dynamic programming approach , time : O(n * sum)
// top down approach 

// int countSubsetsUtil(int set[] , int n , int sum, int dp[101][101] ) {
// 	if (sum == 0 ) return 1 ; 
// 	if ( n == 0 ) return 0 ; 
// 	if (dp[n][sum] != -1 ) return dp[n][sum] ; 

// 	if ( set[n-1] > sum ) 
// 		dp[n][sum] = countSubsetsUtil(set, n-1 , sum , dp ) ; 
// 	else 
// 		dp[n][sum] = countSubsetsUtil(set , n-1 , sum - set[n-1] , dp) + countSubsetsUtil(set , n-1 , sum , dp ) ; 

// 	return dp[n][sum] ; 
// }

// int countSubsets(int set[] , int n , int sum ) {
// 	int dp[101][101] ; 
// 	memset(dp , -1 , sizeof(dp)) ;
// 	return countSubsetsUtil(set , n , sum , dp) ;
// }

// bottom up approach 

int countSubsets(int set[] , int  n , int sum ) {
	int dp[n+1][sum+1]; 
	for(int j= 0 ; j <= sum ; ++j ) dp[0][j] = 0 ;
	for(int i = 0 ; i<= n ; ++i ) dp[i][0] = 1 ; 

	for (int i = 1 ;  i <= n ; ++i ) {
		for(int j = 1 ; j <= sum ; ++j ) {
			if ( set[i-1] > j) dp[i][j] = dp[i-1][j] ; 
			else {
				dp[i][j] = dp[i-1][j - set[i-1]] + dp[i-1][j] ; 
			}
		}
	}
	return dp[n][sum] ; 
}



signed main () {
	int set[] = {3, 1 , 2 , 3, 4 } ;
	int n = sizeof(set)/sizeof(int);
	int sum = 6 ; 
	cout << countSubsets(set ,n , sum) ; 

	return 0; 
}