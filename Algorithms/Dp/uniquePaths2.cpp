/* https://leetcode.com/problems/unique-paths-ii/

*/



int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
	int m = obstacleGrid.size() , n = obstacleGrid[0].size() ;
	int dp[m][n] ; memset(dp , -1 , sizeof(dp)) ;

	for (int i = 0 ; i < m ; ++i ) {
		for (int j = 0 ; j < n ; ++j ) {
			// set 0 for obstacle
			if ( obstacleGrid[i][j] == 1) dp[i][j] = 0 ;
		}
	}

	if ( dp[0][0] == 0 )  return 0 ;
	dp[0][0] = 1 ;

	// filling first row
	for (int j = 1 ; j < n ; ++j ) {
		// it means it is not an obstacle cell
		if ( dp[0][j] == -1) dp[0][j] = dp[0][j - 1 ] ;
		// it is an obstacle cell
		else continue ;
	}

	// filling first column
	for (int i = 1 ; i <  m;  ++i ) {
		// not an obstacle cell
		if ( dp[i][0] == -1) dp[i][0] = dp[i - 1][0] ;
		// obstacle cell
		else continue ;
	}


	for (int i = 1 ; i < m ; ++i ) {
		for (int j = 1 ; j < n ; ++j ) {
			// not an obstacle cell
			if ( dp[i][j] == -1) dp[i][j] = dp[i - 1][j] + dp[i][j - 1 ] ;
			// obstacle cell
			else continue ;
		}
	}
	return dp[m - 1][n - 1] ;


}