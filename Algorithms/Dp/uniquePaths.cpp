/* Given a A X B matrix with your initial position at the top-left cell, find the number of
possible unique paths to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., we can move to
matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

approach is to use dp

dp[i][j] = dp[i - 1][j] + dp[i][j - 1 ] ;

*/



int NumberOfPath(int a, int b)
{
	int dp[a][b] ;
	// filling 1st row
	for (int j = 0 ; j < b; ++j ) dp[0][j]  = 1 ;
	// filling 1st column
	for (int i = 0 ; i  < a ; ++i ) dp[i][0] = 1 ;

	for (int i = 1 ; i < a ; ++i ) {
		for (int j = 1 ; j < b ; ++j ) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1 ] ;
		}
	}

	return dp[a - 1][b - 1] ;
}