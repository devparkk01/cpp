/*
https://leetcode.com/problems/count-square-submatrices-with-all-ones/


*/


class Solution {
public:
	int countSquares(vector<vector<int>>& matrix) {
		int m = matrix.size() , n = matrix[0].size() ;
		int dp[m][n] ;
		memset(dp , 0 , sizeof(dp)) ;
		for (int j = 0 ; j < n ; ++j) dp[0][j] = matrix[0][j] ;
		for (int i = 0 ; i < m ; ++i) dp[i][0] = matrix[i][0] ;

		int count = 0;
		for (int i = 1 ; i < m ; ++i) {
			for (int j = 1 ; j < n ; ++j) {
				if (matrix[i][j] == 1 ) {
					dp[i][j] = min({dp[i - 1][j] , dp[i][j - 1] , dp[i - 1][j - 1]}) + 1;
				}
				else dp[i][j] = 0 ;
			}
		}
		for (int i = 0 ; i < m ; ++i) {
			for (int j = 0 ; j < n ; ++j) count += dp[i][j] ;
		}
		return count ;
	}
};