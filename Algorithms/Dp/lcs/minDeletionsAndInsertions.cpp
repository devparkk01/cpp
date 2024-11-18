/*Given two strings str1 and str2. The task is to remove or insert the minimum number of
 characters from/in str1 so as to transform it into str2.

Input: str1 = "heap", str2 = "pea"
Output: 5

*/

/* approach 1 : use simple dynamic programming

approach 2 : use lcs , it's a variation of lcs problem
total deletions = len(str1) - lcs(str1 , str2)
total insertions = len(str2) - lcs(str1 , str2 )
return deletions + insertions

*/

// approach 1   : using simple dynamic programming

// top down : gives tle if strings are very large
#include<bits/stdc++.h>
using namespace std ;

int mem[501][501]  ;

int util(string x , string y , int m , int n ) {
	if ( n == 0 ) return m ;
	if ( m == 0 ) return n ;

	if (mem[m][n] != -1 ) return mem[m][n] ;

	if (x[m - 1 ] == y[n - 1])  mem[m][n] = util(x , y , m - 1 , n - 1 ) ;
	else mem[m][n] = 1 +  min(util(x, y, m - 1 , n) , util(x , y , m , n - 1 )) ;

	return mem[m][n] ;

}

int minOperations(string str1, string str2)
{
	// Your code goes here
	memset(mem , -1 , sizeof(mem)) ;
	return util(str1 , str2 , str1.length() , str2.length()) ;
}

// bottom up (won't give tle )

int minOperations(string str1, string str2)
{
	int m = str1.length() ;
	int n = str2.length() ;
	int dp[m + 1][n + 1] ;

	for (int i = 0 ; i <= m ; ++i ) {
		for (int j = 0 ; j <= n ; ++j ) {
			if ( i == 0) dp[i][j] = j ;
			else if ( j == 0 ) dp[i][j] = i ;
			else if ( str1[i - 1 ] == str2[j - 1 ]) dp[i][j] = dp[i - 1 ][j - 1 ] ;
			else dp[i ][j] = 1 + min(dp[i - 1 ][j] , dp[i][j - 1]) ;

		}
	}
	return dp[m][n] ;
}


signed main () {
	cout <<  minOperations("heap" , "pea") << endl;
	return 0 ;
}



