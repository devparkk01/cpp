/*Given a rod of length n and a list of prices of rods of length i , where 1 <= i <= n ,
find the optimal way to cut the rod into smaller rods to maximize profit.
length[] = [1, 2, 3, 4]
price [] = [1, 5, 8, 9]
Rod length: 4

Best: Cut the rod into two pieces of length 2 each to gain revenue of 5 + 5 = 10
*/

#include<bits/stdc++.h>
#define endl '\n'
using namespace std ;

// recursive solution
// int rodCutting(int price[] , int n) {
// 	if (n == 0 ) return 0 ;

// 	int maxval = INT_MIN ;
// 	for (int i = 1 ; i <= n ; ++i ) {
// 		maxval = max(maxval , price[i - 1 ] + rodCutting(price , n - i )) ;
// 	}
// 	return maxval ;

// }

// top down approach

// int rodCuttingUtil(int price[] , int n , int mem[] ) {
// 	if ( n == 0 ) return 0 ;
// 	if ( mem[n] != -1 ) return mem[n] ;

// 	mem[n] = INT_MIN ;
// 	for (int i = 1 ; i <= n ; ++i ) {
// 		mem[n] = max(mem[n] , price[i - 1 ] + rodCuttingUtil(price , n - i , mem )) ;
// 	}
// 	return mem[n] ;
// }

// int rodCutting(int price[] , int n ) {
// 	int mem[n + 1 ] ;
// 	memset(mem , -1 , sizeof(mem)) ;
// 	return rodCuttingUtil(price , n , mem ) ;
// }


// bottom up
int rodCutting(int price[] , int n ) {
	int dp[n + 1 ] ;
	dp[0] = 0 ;

	for (int i = 1 ; i <= n ; ++i ) {
		dp[i] = INT_MIN ;
		for (int j = 1 ; j <= i ; ++j ) {
			dp[i] = max(dp[i] , price[j - 1 ] + dp[i - j ]) ;
		}
	}

	return dp[n] ;
}

signed main() {
	int price[] = {1, 5, 8, 9, 10, 17, 17, 20} ;
	int n = sizeof(price) / sizeof(int ) ;
	cout << rodCutting(price , n ) << endl;


	return 0 ;
}

