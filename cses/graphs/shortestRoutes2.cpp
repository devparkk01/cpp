#include<bits/stdc++.h>
using namespace std ; 
#define INF 1000000000000
#define ll long long 

void shortestPath(vector<vector<ll>>&dp , vector<vector<ll>>&grid, int n  ) {
	for(int i = 1 ; i <=n ; ++i ) {
		for(int j = 1 ; j <= n ; ++j ) {
			dp[i][j] = grid[i][j] ; 
		}
	}
	for(int k = 1 ; k <= n ; ++k) {
		for(int i = 1 ; i <= n; ++i ) {
			for (int j = 1 ; j <= n ; ++j ) {
				if (dp[i][k] == INF || dp[k][j] == INF)  continue ; 
				else  
					dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j]) ; 
			}
		}
	}

}

signed main () {
	int n , m ,	q ; 
	cin >> n >> m >> q; 
	vector<vector<ll>>grid(n+1 , vector<ll>(m+1 ,INF)) ; 
	int u , v, wt ; 
	for(int i = 0 ; i < m ; ++i ) {
		cin >>u >> v >> wt ; 
		grid[u][v] = wt ; 
		// grid[v][u] = wt ; 
	}
	vector<vector<ll>>dp(n+1 , vector<ll>(m+1 )) ; 
	shortestPath(dp , grid , n ) ; 
	// int a, b ; 
	// while (q-- ) {
	// 	cin >> a >> b; 
	// 	if ( dp[a][b] == INF) cout << "-1 " << endl; 
	// 	else cout << dp[a][b] << " " << endl; 
	// }
	for(int i = 1 ; i <= n; ++i ) {
		for(int j = 1 ;  j <= n ;++j ) {
			cout << dp[i][j] <<" " ; 
		}
		cout << endl; 
	}

	return 0 ; 

}