int maxGold(int n, int m, vector<vector<int>> M)  {
    int dp[n][m] ;
    for (int i = 0 ; i < n ; ++i ) dp[i][0] = M[i][0] ;

    for (int j = 1 ; j < m ; ++j ) {
        for (int i = 0 ; i < n ; ++i) {
            dp[i][j] = M[i][j] ;
            int temp = dp[i][j - 1 ] ;
            if ( i - 1 >= 0) {
                temp = max(temp , dp[i - 1 ][j - 1 ]) ;
            }
            if ( i + 1 <= n - 1 ) {
                temp = max(temp , dp[i + 1][j - 1 ])  ;
            }
            dp[i][j] += temp ;

        }
    }


    int ans = 0 ;
    for (int i = 0 ; i < n ; ++i) ans = max(ans , dp[i][m - 1 ]) ;
    return ans;

}