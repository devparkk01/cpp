/*  Longest palindromic subsequence is finding the length of longest subsequence of a string
that is also  a palindrome .

https://leetcode.com/problems/longest-palindromic-subsequence/

*/



#include<bits/stdc++.h>
using namespace std ;


// recursive approach, time : O(2 ^n )

// int lps(string s , int  start , int end ) {
// 	if (start < end ) return 0 ;
// 	if  (start == end  ) return 1 ;
// 	if ( s[start] == s[end ]) return 2 + lps(s , start + 1 , end - 1 ) ;
// 	else
// 		return max(lps(s, start + 1  , end ) , lps(s , start , end - 1 )) ;

// }

// top down approach ( gives tle, if string is very large ), time : O(n ^2 ) , space : O(n^2)
int lpsutil(string s , int start , int end , int dp[101][101] ) {
	if ( start > end ) return 0 ;
	if ( start == end ) return 1 ;
	if (dp[start][end] != -1 ) return dp[start][end ] ;

	if ( s[start] == s[end]) dp[start][end] = 2 + lpsutil(s , start + 1 , end - 1 , dp) ;
	else dp[start][end] = max(lpsutil(s, start + 1 , end , dp ), lpsutil(s, start, end - 1 , dp));

	return dp[start][end]  ;
}

int lps(string s) {
	int dp[101][101] ;
	memset(dp , -1 , sizeof(dp)) ;
	return lpsutil(s , 0 , s.length() - 1 , dp ) ;
}

signed main() {
	string s = "abbdacb" ;
	cout << lps(s) << endl ;
	return 0 ;
}