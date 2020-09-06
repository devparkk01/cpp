/* find the total no of connected components in a graph . 
time : O(V+E) , space : O(V)
we can do any traversal (bfs or dfs)
here we will do dfs 
*/

include <bits/stdc++.h>
using namespace std;


void dfsUtil (vector<int>g[] , vector<bool>&visited , int u ) {
	visited[u] = true ; 
	for(int x : g[u]) {
		if (!visited[x]) {
			dfsUtil(g ,  visited , x ) ; 
		}
	}
}

int main() {
	int n ; int m ;

	cin >> n >> m ;
	vector<int>g[n+1] ;int u , v ; 
	for(int i = 0 ; i < m ;++i ) {
		cin >> u >> v ; 
		g[u].push_back(v) ;
		g[v].push_back(u) ; 
	}
	int count = 0 ;
	vector<bool>visited(n+1) ; 
	for(int u = 1 ; u <= n ; ++u ) {
		if (!visited[u]) {
			count++ ; 
			dfsUtil(g , visited , u) ; 
		}
	}
	cout << count ; 
	return 0;
}