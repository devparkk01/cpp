/*
Given a grid of size M*N with each cell consisting of an integer which represents points.
 We can move across a cell only if we have positive points. Whenever we pass through a cell,
points in that cell are added to our overall points, the task is to find minimum initial points
 to reach cell (m-1, n-1) from (0, 0) by following these certain set of rules :

1. From a cell (i, j) we can move to (i + 1, j) or (i, j + 1).
2. We cannot move from (i, j) if your overall points at (i, j) are <= 0.
3. We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

https://practice.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1
*/


int minPoints(vector<vector<int>> points, int M, int N)
{
	int dp[M][N] ;
	int minpointsonexit = 1 , minpointsonentry ;
	minpointsonentry = max(minpointsonexit - points[M - 1 ][ N - 1] , 1 ) ;
	dp[M - 1][N - 1] = minpointsonentry ;
	// filling last row

	for (int j = N - 2 ; j >= 0 ; --j ) {
		minpointsonexit = dp[M - 1 ][j + 1] ;
		minpointsonentry = max(minpointsonexit - points[M - 1][j] , 1 ) ;
		dp[M - 1][j] = minpointsonentry ;
	}
	// filling last col

	for (int i = M - 2 ; i >= 0 ; --i) {
		minpointsonexit = dp[i + 1 ][N - 1] ;
		minpointsonentry = max(minpointsonexit  - points[i][N - 1] , 1 ) ;
		dp[i][N - 1] = minpointsonentry ;
	}

	for (int i = M - 2 ; i >= 0 ; --i) {
		for (int j = N - 2 ; j >= 0 ; --j) {
			minpointsonexit = min(dp[i + 1][j] , dp[i][j + 1]) ;
			minpointsonentry = max(minpointsonexit - points[i][j] , 1 );
			dp[i][j] = minpointsonentry ;
		}
	}

	return dp[0][0] ;


}