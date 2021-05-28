
/*
Given a floor of size n x 4 and tiles of size 1 x 4.The problem is to count the
number of ways to tile the given floor using 1 x 4 tiles. A tile can either be placed
horizontally or vertically.

*/
class Solution {
public:
	long long arrangeTiles(int N) {
		long long dp[N + 1 ] ;

		for (int i = 0 ; i <= N ; ++i ) {
			if (i < 4) dp[i] = 1 ;
			else {
				dp[i] = dp[i - 1] + dp[i - 4] ;
			}
		}
		return dp[N] ;
	}

};



/*
This is more generic problem

Given a floor of size n x m and tiles of size 1 x m. The problem is to count the number of
ways to tile the given floor using 1 x m tiles. A tile can either be placed horizontally or
vertically.
*/

int mod = 1e9 + 7  ;
class Solution {
public:
	int countWays(int n, int m) {
		int dp[n + 1 ] ;
		for (int i = 0 ; i <= n ; ++i ) {
			if (i < m) dp[i] = 1 ;
			else {
				dp[i] = (dp[i - 1 ] + dp[i - m ]) % mod ;
			}
		}
		return dp[n] ;

	}
};