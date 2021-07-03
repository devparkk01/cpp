/*
https://practice.geeksforgeeks.org/problems/distinct-occurrences/1#

really good question
*/

int mod = 1e9 + 7 ;
class Solution
{
public:
	int subsequenceCount(string S, string T)
	{
		int n = S.length() , m = T.length();
		int dp[n + 1][m + 1] ;
		memset(dp , 0 , sizeof(dp)) ;

		for (int j = 0 ; j <= m ; ++j)  dp[0][j] = 0 ;
		for (int i = 0 ; i <= n ; ++i) dp[i][0] = 1 ;


		for (int i = 1 ; i <= n ; ++i ) {
			for (int j = 1 ; j <= m ; ++j) {
				if (S[i - 1] == T[j - 1]) {
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod ;
				}
				else dp[i][j] = dp[i - 1][j] ;
			}
		}
		return dp[n][m] ;

	}
};
