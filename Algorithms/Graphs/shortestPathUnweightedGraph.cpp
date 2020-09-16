#include<bits/stdc++.h>
using namespace std ; 

#define ipair pair<int, int > 

int bfs(vector<int>adj[] , int V , int src , int dest ) {
	vector<bool>visited(V) ;
	queue<ipair>q; 
	q.push({src , 0 }) ;
	visited[src] = true ; 
	vector<int>parent(V); 
	parent[src] = -1 ; 

	int u ; int dist ; 
	while (!q.empty()) {
		u = q.front().first  ; dist = q.front().second ; 
		q.pop() ; 
		if( u == dest ) {
			cout << "Printing path : "  ; 
			int x = dest  ; 
			while (x!=-1 ) {
				cout << x << " " ; 
				x = parent[x] ; 
			}
			cout << endl; 
			return dist ; 
		}

		for(int v : adj[u]) {
			if ( !visited[v]) {
				q.push({v,  dist +1 }) ;
				visited[v] =  true ; 
				parent[v] = u ; 
			}
		}
	}
	return -1 ; 
}


signed main (){
	int V = 4; 
	int E = 4 ;
	vector<int>adj[V] ; 
	adj[0].push_back(2) ; 
	adj[2].push_back(0) ; 
	adj[1].push_back(2) ;
	adj[2].push_back(1) ; 
	adj[2].push_back(3) ; 
	adj[3].push_back(2) ;
	adj[1].push_back(3) ;
	adj[3].push_back(1) ; 

	cout << bfs(adj , V , 0 , 3) << endl ; 


	return 0 ; 
}