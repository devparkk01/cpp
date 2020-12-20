/*Given two strings str1 and str2 and below operations that can performed on str1.
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace
All of the above operations are of equal cost.

*/

#include<bits/stdc++.h>
#define vec vector
using namespace std ;

/* brute force approach
time : O(3 ^ n )
*/
// int editDist(string x , int m , string y , int n ) {
// 	if ( m == 0 ) return n ;
// 	if ( n == 0 ) return m ;
// 	if ( x[m - 1 ] == y[n - 1]) return editDist(x , m - 1 , y , n - 1 ) ;
// 	else {
// 		int ins = editDist(x , m , y , n - 1 ) + 1 ;
// 		int del = editDist(x , m - 1 , y , n) +  1 ;
// 		int rep = editDist(x , m - 1 , y  , n - 1 ) + 1 ;
// 		return min ({ins , del , rep }) ;
// 	}
// }


/*
Top down
*/

// int editDistUtil(string x , int m , string y , int n , vec<vec<int>>&mem ) {
// 	if ( m == 0 ) return n ;
// 	if ( n == 0 ) return m ;
// 	if ( mem[n][m] != -1 ) return mem[n][m] ;
// 	else {
// 		if ( x[m - 1] == y[n - 1 ]) mem[n][m] = editDistUtil(x, m - 1 , y , n - 1, mem) ;
// 		else {
// 			int ins = editDistUtil(x , m , y , n - 1 , mem) + 1  ;
// 			int del = editDistUtil(x , m - 1 , y , n  , mem) + 1 ;
// 			int rep = editDistUtil(x , m - 1 , y , n - 1 , mem ) + 1 ;
// 			mem[n][m] = min({ins , del , rep  }) ;
// 		}
// 		return mem[n][m] ;
// 	}
// }


// int editDist(string x , int m , string y , int n ) {
// 	vec<vec<int>>mem(n + 1 , vec<int>(m + 1 ,  -1 )) ;
// 	return editDistUtil(x , m , y , n , mem ) ;
// }

/* Bottom up approach
   time : O(m * n ) , space : O(m * n )
*/

int editDist(string x , int m , string y , int n ) {
	vec<vec<int>>dp(n + 1 , vec<int>(m + 1 )) ;
	for (int i = 0 ; i <= n ; ++i ) {
		for (int j = 0 ; j <= m ; ++j ) {
			if ( i == 0 ) dp[i][j] = j ;
			else if ( j == 0 ) dp[i][j] = i ;
			else if ( x[j - 1 ] == y[i - 1 ]) dp[i][j] = dp[i - 1][j - 1]  ;
			else {
				int del = dp[i - 1][j] + 1 ;
				int ins = dp[i][j - 1 ] + 1 ;
				int rep = dp[i - 1][j - 1] + 1 ;
				dp[i][j] = min({ins , del , rep }) ;
			}
		}
	}
	return dp[n][m] ;
}

signed main () {
	string x = "geek", y = "gesek";
	cout << "The Levenshtein Distance is " <<
	     editDist(x, x.length(), y, y.length());

	return 0;
}


