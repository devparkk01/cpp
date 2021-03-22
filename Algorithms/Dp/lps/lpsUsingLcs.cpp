
/* We know that top down approach of lps will give tle . Therefore we need to go with bottom up .

One more thing is that ,lps is a variation of lcs . We can calculate lps using lcs by calling
lcs on the original string and its reversed string , i.e , call lcs(s , reverse(s)) .
This should do the job , since bottom up approach of lcs is quite intuitive

*/

#include<bits/stdc++.h>
using namespace std;

// lcs using bottom up
int lcs(string r , string s ) {
	int n = r.length() ;
	int dp[n + 1 ][n + 1 ] ;

	for (int i = 0 ; i  <= n ; ++i ) {
		for (int j = 0 ; j <= n ; ++j) {
			if ( i == 0 || j == 0 ) dp[i][j ] = 0;
			else if ( r[i - 1 ] == s[j - 1 ]) dp[i][j] = 1 + dp[i - 1][j - 1] ;
			else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1 ]);
		}
	}
	return dp[n][n] ;

}

// calculating lps using lcs
int lps(string s ) {
	string r = s ;
	reverse(s.begin() , s.end()) ;
	return lcs(r , s ) ;

}

signed main() {
	string s = "abbdacb" ;
	cout << lps(s) << endl ;
	return 0 ;
}