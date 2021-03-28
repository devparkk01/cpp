#include<bits/stdc++.h>
using namespace std ; 
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL ) ;
#define ipair pair<long long , long long> 
#define INF 9223372036854775807

void dijkstra(vector<ipair>graph[] , int V ) {
	vector<long long > dist(V ,INF ) ;
	vector<bool>visited(V) ; 
	priority_queue<ipair , vector<ipair> , greater<ipair> > pq ; 
	dist[0] = 0 ; 
	pq.push({0 , 0}) ; 

	int u , v ; 
	while (!pq.empty() ) {
		u = pq.top().second ;
		visited[u] = true; 
		pq.pop() ;  
		for(ipair x : graph[u]) {
			v = x.first ; 
			if ( !visited[v] && dist[v] > dist[u] + x.second ) {
				dist[v] = dist[u] + x.second ; 
				pq.push({dist[v] , v}) ; 
			}
		}
	}
	for(int i = 0 ;i < V ; ++i ) {
		cout << dist[i] << " " ;
	}
}



signed main () {
	fastio ; 
	int V, E ; cin >> V >> E ; 
	vector<ipair>graph[V] ;
	int u1, u2 , wt ; 
	for(int i= 0 ; i < E ; ++i ) {
		cin >> u1 >> u2 >> wt ; 
		u1-- ; u2-- ; 
		graph[u1].push_back({u2, wt}) ; 
	}
	dijkstra(graph , V) ; 
	return 0 ; 
}