#include<bits/stdc++.h>
using namespace std ;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define endl '\n'
#define ll long long
#define f(i , k , n ) for(int i = k ; i < n ; ++i)
#define ip pair<int , int >
#define um unordered_map<int , int >
#define us unordered_set<int >
#define vec vector
#define pb push_back

int mod = 1e9 + 7 ;


signed main () {
#ifndef ONLINE_JUDGE
	freopen("input1.txt" , "r" , stdin) ;
	freopen("output1.txt" , "w" , stdout) ;
#endif

	fastio  ;
	int n ; cin >> n ; int dp[n][n] ; memset(dp , -1 , sizeof(dp)) ;
	char c;
	f(i , 0 , n ) {
		f(j , 0 , n ) {
			cin >> c ;
			if ( c == '*') dp[i][j] = 0 ;
		}
	}

	if (dp[0][0] == 0 ) { cout << 0 ; return 0 ; }

	dp[0][0] = 1 ;
	f(j , 1 , n ) {
		if ( dp[0][j] == 0) continue ;
		else dp[0][j] = dp[0][j - 1 ] ;
	}
	f(i , 1 , n ) {
		if (dp[i][0] == 0 ) continue  ;
		else dp[i][0] = dp[i - 1 ][0] ;
	}

	f(i , 1 , n ) {
		f(j , 1 , n ) {
			if (dp[i][j] == 0 ) continue ;
			else dp[i][j] = (dp[i - 1 ][j] + dp[i][j - 1 ] ) % mod ;
		}
	}

	cout << dp[n - 1 ][n - 1 ] ;

	return 0 ;

}