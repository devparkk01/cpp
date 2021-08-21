/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/


*/

/*
time : O(n*n*k) , space : O( n * k )

*/


class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size() ;
		int dp[k + 1 ][n] ;

		for (int t = 0 ; t <= k ; ++t ) {
			for (int i = 0 ; i < n ; ++i) {
				if (t == 0 || i == 0 ) {
					dp[t][i] = 0 ;
				}
				else {
					int sell_on_i = 0 ;
					for (int j = 0 ; j <  i ; ++j) {
						sell_on_i = max(sell_on_i, dp[t - 1][j] - prices[j] + prices[i]);
					}
					dp[t][i] = max(dp[t][i - 1] , sell_on_i ) ;
				}
			}
		}
		return dp[k][n - 1 ];

	}
};

/*
optimized approach , time : O(n *k ) , space : O(n *  k)

*/

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size() ;
		if ( n == 0 || k == 0 ) return 0 ;
		int dp[k + 1 ][n] ;

		for (int t = 0 ; t <= k ; ++t ) {
			int prev_max = INT_MIN ;
			for (int i = 0 ; i < n ; ++i) {
				if (t == 0 || i == 0 ) {
					dp[t][i] = 0 ;
				}
				else {
					prev_max = max(prev_max , dp[t - 1][i - 1] - prices[i - 1]) ;
					int sell_on_i = prev_max + prices[i] ;

					dp[t][i] = max(dp[t][i - 1] , sell_on_i ) ;
				}
			}
		}
		return dp[k][n - 1 ];

	}
};