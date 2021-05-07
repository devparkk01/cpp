/*A matrix is given , cost[][] . cost[i][j] represents cost to traverse  through that cell .
We are initially at cell(0,0) . Find the cost of minimum cost path to reach bottom right cell .
We can move in only 3 directions ( down , right , diagonal down ) .


Approach : Use dp

dp[i][j] = cost[i][j] + min({dp[i - 1 ][j] , dp[i - 1][j - 1] , dp[i][j - 1]}) ;

time : O(m*n) , space : O(m *n )
*/
// m is row , n is column
int minCost(int cost[1001][1001] , int m , int n ) {
	int dp[m][n] ;
	dp[0][0] = cost[0][0] ;
	// dp[i][j] stores min cost to reach cell(i , j )

	// filling 1st row
	for (int j = 0 ; j < n ; ++j )dp[0][j] = dp[0][j - 1 ] + cost[0][j] ;
	// filling 1st column
	for (int i = 0 ; i < m ; ++i) dp[i][0] = dp[i - 1 ][0] + cost[i][0] ;

	for (int i = 1 ; i < m ; ++i ) {
		for (int j = 1 ; j < n ; ++j) {
			dp[i][j] = cost[i][j] + min({dp[i - 1 ][j] , dp[i - 1][j - 1] , dp[i][j - 1]}) ;
		}
	}
	return dp[m - 1][n - 1] ;
}