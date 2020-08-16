/*Suppose you have N eggs and you want to determine from which floor(threshold floor ) in a k-floor
building you can drop an egg such that it does not break. You have to determine the minimum number of 
attempts you need to  find the threshold floor in the worst case while using the best strategy . 

time : O(N * K * K) , space : O(N * K)

*/

#include<bits/stdc++.h>
using namespace std ; 


int eggDrop(int n , int k ) {
	int dp[n+1][k+1] ; 
	for(int i = 1 ; i <= n; ++i ) {
		dp[i][1] = 1 ; 
		dp[i][0] = 0 ; 
	}
	for(int j = 1 ; j<= k ; ++j ) {
		dp[1][j] = j ; 
	}
	for(int i = 2 ;i <=n ; ++i ) {
		for(int j = 2  ; j<=k ; ++j ) {
			dp[i][j] = INT_MAX ;
			int res ;
			for(int x = 1 ; x <= j ; ++x ) {
				res = 1 + max(dp[i-1][x-1], dp[i][j-x]);  
				dp[i][j] = min(dp[i][j] , res ) ; 
			}
		}
	}
	return dp[n][k] ; 

}


int main () {
	int n = 2; int k =  100 ; 
	cout << "Minimum no of attempts needed to find threshold floor : " << eggDrop(n , k ) << endl ; 
	return 0; 

}