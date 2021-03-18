/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a
different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot
achieve any profit, return 0.

*/

// Brute force approach is O(n^2) time

/* Valley-peak approach .
	time : O(n) , below is the implementation of valley peak approach

*/

#include<bits/stdc++.h>
#define endl '\n'

using namespace std ;

int maxProfit(vector<int>& prices) {
	int maxpro = 0 ;
	int minprice = prices[0] ;

	for (int i = 1 ; i < prices.size() ; ++i ) {
		if ( prices[i] < minprice ) minprice = prices[i] ;
		maxpro = max(maxpro , prices[i] - minprice ) ;
	}
	return maxpro ;

}


signed main() {
	vector<int>prices = {7, 1, 5, 3, 6, 4 } ;
	cout << maxProfit(prices ) << endl;
	return 0 ;
}