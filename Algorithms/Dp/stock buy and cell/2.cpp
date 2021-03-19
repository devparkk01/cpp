/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete as many transactions as you like
 (i.e., buy one and sell one share of the stock multiple times).
Note: You may not engage in multiple transactions simultaneously (i.e., you must
sell the stock before you buy again).

*/

#include<bits/stdc++.h>
using namespace std ;

// 1st approach , Valley peak approach
// time : O(n) , space : O(1 )


// int maxProfit(vector<int>& prices) {
// 	int i = 0 ;
// 	int n = prices.size() ;
// 	int valley , peak ;
// 	int maxpro = 0 ;
// 	while (i < n - 1 ) {

// 		// finding a valley ( local minima )
// 		while ( i  < n - 1 && prices[i] >= prices[i + 1 ]) { i++ ;}
// 		if ( i == n - 1 ) break ;
// 		valley = prices[i] ;
// 		// finding a peak ( local maxima )
// 		while ( i < n - 1 && prices[i] <= prices[i + 1 ]) { i++ ; }

// 		peak = prices[i] ;
// 		maxpro += (peak - valley ) ;

// 	}
// 	return maxpro ;
// }


// 2nd approach ,  time : O(n) , space : O(1)
int maxProfit(vector<int>& prices) {
	int n = prices.size() ;
	int maxPro = 0 ;

	for (int i = 1 ; i < n ; ++i ) {
		if ( prices[i] > prices[i - 1 ]) {
			maxPro += (prices[i] - prices[i - 1 ]) ;
		}
	}
	return maxPro ;
}

signed main () {

	vector<int>prices = {11 , 3, 8 , 9 , 6 , 14, 21 , 5} ;
	cout << maxProfit(prices ) << endl;

	return 0 ;
}