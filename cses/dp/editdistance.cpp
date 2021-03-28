
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

int dp[5001][5001] ;


int solve(string x , string y , int m , int n ) {
	for (int i = 0 ; i <= m ; ++i ) {
		for (int j = 0 ; j <=  n ; ++j ) {
			if ( i == 0 ) dp[i][j] = j ;
			else if ( j == 0 ) dp[i][j] = i ;
			else if ( x[i - 1 ] == y[j - 1 ]) dp[i][j] = dp[i - 1 ][ j - 1 ] ;
			else {
				int ins = 1  + dp[i][j - 1 ] ;
				int del = 1 + dp[i - 1 ][j] ;
				int rep = 1 + dp[ i - 1 ][ j - 1 ] ;
				dp[i ][j] = min({ins , del , rep }) ;
			}

		}
	}
	return dp[m][n] ;
}


signed main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt" , "r" , stdin) ;
// 	freopen("output1.txt" , "w" , stdout) ;
// #endif

	fastio  ;
	string x , y  ; cin >> x >> y ;
	cout << solve(x , y , x.length() , y.length()) ;
	return 0 ;

}