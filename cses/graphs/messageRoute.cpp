#include<bits/stdc++.h>
using namespace std ; 
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL) ; cout.tie(NULL ) ; 
#define endl '\n' 
#define ipair pair<int, int> 

void bfs(vector<int>adj[] , int n  ) {
	vector<bool>visited(n+1) ; 
	queue<ipair>q ; 
	vector<int>parent(n+1) ; 
	q.push({1 , 1 }) ; 
	visited[1] = true ; 
	parent[1] = -1 ; int u , dist ; 

	while(!q.empty()) {
		u  = q.front().first ; dist = q.front().second ; 
		q.pop() ; 
		if(u == n) {
			cout << dist << endl; 
			stack<int>stk ; int x = n ;
			while(x != -1 ) {
				stk.push(x) ;
				x = parent[x] ; 
			}
			while (!stk.empty()) {
				cout << stk.top() << " " ;
				stk.pop() ; 
			}
			return ; 
		}

		for(int v : adj[u]) {
			if(!visited[v]) {
				q.push({v , dist+1}) ; 
				visited[v] = true ; 
				parent[v ] = u ; 
			}

		}
	}
	cout << "IMPOSSIBLE" << endl; 

}




signed main() {
	fastio ; 
	int n , m ; 
	cin >> n >> m; 
	vector<int>adj[n+1] ;
	int u , v ; 
	for(int i = 1 ; i <= m ; ++i ) {
		cin >> u >> v; 
		adj[u].push_back(v) ;
		adj[v].push_back(u) ; 
	}
	bfs(adj , n ) ;

	return 0 ; 
}