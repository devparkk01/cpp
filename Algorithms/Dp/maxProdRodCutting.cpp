/*Given a rod of length n , find the optimal way to cut the rod into smaller rods to maximize
the product of each of the smaller rod’s price. Assume each rod of length i has price i .

Approach : This problem is similar to rod cutting problem . There we had to maximize the sum of
the total profit , here we have to maximize the product of the total profit  .

*/

#include<bits/stdc++.h>
using namespace std ;

#define endl '\n'

// recursive , time : O(n^n)

// int maxProdProfit(int n ) {
// 	if ( n == 1 ) return 1 ;

// 	int maxprofit = n ;
// 	for (int i = 1 ; i < n ; ++i ) {
// 		maxprofit = max(maxprofit , i * maxProdProfit(n - i )) ;
// 	}
// 	return maxprofit ;
// }


// top down , time : O(n * n ) , space : O(n)

// mem[i] stores max profit(product) obtained for a rod of length i

int maxProdProfitUtil(int n , int mem[]) {
	if (n == 1 ) return 1 ;
	if ( mem[n] != -1 ) return mem[n];

	mem[n] = n ;
	for (int i = 1 ; i < n ; ++i ) {
		mem[n] = max(mem[n] , i * maxProdProfitUtil(n - i, mem)) ;
	}
	return mem[n] ;
}

int maxProdProfit(int n ) {
	int mem[n + 1] ;
	memset(mem , -1 , sizeof(mem)) ;
	return maxProdProfitUtil(n , mem ) ;
}

signed main() {
	int n = 15 ;
	cout << maxProdProfit(n ) << endl;

	return 0 ;
}