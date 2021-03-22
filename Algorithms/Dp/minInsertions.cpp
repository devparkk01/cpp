/*Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.

This question is variation of lps , which in turn is a variation of lcs.
simply , we can find lps and subtract it from the length of the string to get the
minimum no of insertions  required  .

*/

// top down (not using lps) , will give tle

int util(string s , int start , int end , int dp[101][101]) {
	if ( start > end ) return 0 ; // there is no substring
	if ( start == end ) return 0 ; // there is only one character,so no need to insert any character

	if ( dp[start][end] != -1 ) return dp[start][end] ;
	if ( s[start] == s[end]) dp[start][end] = util(s , start + 1, end - 1 , dp ) ;
	else
		dp[start][end] = 1 + min(util(s, start + 1 , end , dp), util(s, start , end - 1 , dp)) ;
	return dp[start][end]  ;

}

int minInsertions(string s) {
	int dp[101][101] ;
	memset(dp , -1 , sizeof(dp)) ;
	return util(s , 0 , s.length() - 1 , dp ) ;

}

// top down (using lps ) ,will give tle

int dp[101][101] ;
int lps(string s , int start , int end ) {
	if ( start > end ) return 0 ;
	if ( start == end ) return 0 ;
	if ( dp[start][end] != -1 ) return dp[start][end] ;

	if ( s[start ] == s[end ]) dp[start][end] = 2 + lps(s , start + 1 , end - 1 ) ;
	else dp[start][end] = max( lps(s , start + 1 , end ) , lps(s , start , end - 1 ));

	return dp[start][end] ;
}

int minimumNumberOfDeletions(string S) {
	memset(dp , -1 , sizeof(dp)) ;
	int n = S.length() ;
	return n - lps(S , 0 , n - 1 ) ;

}


/* bottom up . using lcs
	time : O(n*n) , space : O(n * n )
*/
int minInsertions(string str) {
	string str2 = str ;
	reverse(str.begin() , str.end()) ;
	int n = str.length() ;
	int dp[n + 1 ][n + 1 ] ;

	for (int i = 0 ; i <= n  ; ++i ) {
		for (int j = 0 ; j <= n ; ++j) {
			if ( i == 0 || j == 0) dp[i][j] = 0 ;
			else if ( str[i - 1] == str2[j - 1 ] ) dp[i][j] = 1 + dp[i - 1][j - 1 ] ;
			else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1 ]) ;
		}
	}
	int lcs = dp[n][n] ;
	return n - lcs ;

}

