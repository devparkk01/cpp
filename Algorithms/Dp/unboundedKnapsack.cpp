/*Given a knapsack weight W and a set of n items with certain value val[i] and weight wt[i],
we need to calculate the maximum amount that could make up this quantity exactly.
This is different from classical Knapsack problem,
here we are allowed to use unlimited number of instances of an item.

*/

#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'

// recursive approach
// int knapSack(int N, int W, int val[], int wt[])
// {
// 	if ( W == 0 ) return 0 ;
// 	int maxprofit = 0 ;

// 	for (int i = 0 ; i < N ; ++i ) {
// 		if ( wt[i] <= W ) {
// 			maxprofit = max(maxprofit, val[i] + knapSack(N, W - wt[i] , val, wt )) ;
// 		}

// 	}
// 	return maxprofit ;
// }


// top down approach, time : O(N *W ) , space : O(W)
// int knapSackUtil(int N, int W, int val[], int wt[], int mem[]) {
// 	if ( W == 0 ) return 0 ;
// 	if ( mem[W] != -1  )  return mem[W] ;

// 	mem[W] = 0 ;
// 	for (int i = 0 ; i < N ; ++i ) {
// 		if ( wt[i] <= W ) {
// 			mem[W] = max(mem[W], val[i] + knapSackUtil(N, W - wt[i] , val, wt, mem )) ;
// 		}

// 	}
// 	return mem[W] ;

// }

// int knapSack(int N, int W, int val[], int wt[]) {
// 	int mem[W + 1 ]  ;
// 	memset(mem , -1 ,  sizeof(mem)) ;

// 	return knapSackUtil(N , W , val , wt , mem )  ;

// }

// Bottom up approach

int knapSack(int N , int W , int val[] , int wt[] ) {
	int dp[W + 1 ] = {0} ;

	for (int i = 1 ; i <= W ; ++i ) {
		for (int j = 0 ; j < N ; ++j ) {
			if ( wt[j] <= i ) {
				dp[i] = max(dp[i] , val[j] +  dp[i - wt[j]] ) ;
			}
		}
	}
	return dp[W] ;

}

signed main() {
	int W = 100;
	int wt[] = {1 , 50 } ;
	int val[] = {1 , 30} ;
	int N = sizeof(wt) / sizeof(int ) ;
	cout << knapSack(N , W,  val , wt ) ;

	return 0 ;
}


