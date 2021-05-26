/*Given a set of integers , the task is to divide it into two sets s1 and s2 such that
the absolute difference between their sums is minimum .

*/

/* This problem is a  variation of subset sum problem .
Dp approach , time : O(n * sum )
*/

int minSubsetSumDiff(int arr[] , int n ) {
    int totalSum = accumulate(arr , arr + n , 0 ) ;
    int sum = totalSum / 2 ;
    bool dp[n + 1][sum + 1] ;
    for (int j = 0 ; j <= sum ; ++j) dp[0][j] = false ;
    for (int i = 0 ;  i <= n ; ++i ) dp[i][0] = true ;

    for (int i = 1 ; i <= n ; ++i ) {
        for (int j = 1 ; j <= sum ; ++j ) {
            if ( arr[i - 1] > j )
                dp[i][j] = dp[i - 1][j] ;
            else {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j] ;
            }
        }
    }
    int s1 , s2 ;
    for (int j =  sum ; j >= 0 ; --j) {
        if (dp[n][j] == true ) {
            s1 = j ;
            break ;
        }
    }
    s2 = totalSum -  s1 ;
    return abs(s1 - s2 ) ;

}
