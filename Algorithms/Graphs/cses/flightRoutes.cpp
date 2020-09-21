#include<bits/stdc++.h>
using namespace std ; 
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define ipair pair<int, int> 

void bfs(vector<ipair>adj[] ,  int n , int k ) {
	vector<int>res ; res.reserve(k) ;
	int count = 0 ; 
	queue<ipair>q ; 
	q.push({1 , 0 }) ; 
	int u , wt ; 
	while (!q.empty() ) {
		u = q.front().first ; wt = q.front().second ; 
		q.pop() ; 
		if ( u == n ) {
			count++ ; 
			res.push_back(wt) ;
			if ( count == k) break ;
		}
		for(ipair x : adj[u] ) {
			q.push({x.first , x.second + wt }) ; 
		}
	}
	sort(res.begin() , res.end() ) ; 
	for(int i =0  ; i  < k ; ++i ) {
		cout << res[i] << " " ;
	}

}

signed main (){
	fastio ; 
	int n , m , k ; 
	cin >> n >> m >> k ;
	vector<ipair>adj[n + 1] ; 
	int u , v , wt ; 
	for(int i = 0 ; i < m ; ++i ) {
		cin >> u >> v >> wt ; 
		adj[u].push_back({v , wt }) ; 
	}
	bfs(adj , n , k ) ;
	return 0 ; 

}