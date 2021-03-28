#include<bits/stdc++.h>
using namespace std ; 
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define INF 9223372036854775807


int minDist (vector<long long> &dist ,vector<bool>&sptSet ,  int V ) {
	long long min = INF  ;  int min_vertex ; 
	for(int i = 0 ;i < V ; ++i ) {
		if( !sptSet[i] && min > dist[i]) {
			min = dist[i] ; min_vertex = i ;  
		}
	}
	return min_vertex  ; 
}



void shortestPath (vector<vector<int>> &graph , int V , int E) {
	vector<long long>dist(V , INF ) ; 
	vector<bool>sptSet(V) ;
	dist[0] = 0 ; 
	int u ;
	for(int count = 0 ; count < V-1 ; ++count ) {
		u = minDist(dist , sptSet , V) ; 
		sptSet[u] = true ; 
		for(int v = 0 ; v < V ; ++v) {
			//  check path exists from src to u 
			if ( graph[u][v] && sptSet[v] == false && dist[u] != INF && dist[v] > dist[u] + graph[u][v]) {
				dist[v] = dist[u ] + graph[u][v] ; 
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
	
	vector<vector<int >>graph(V , vector<int>(V)) ; 
	int u1 , u2 , wt ; 
	for(int i = 0 ;i < E ; ++i ) {
		cin >> u1  >> u2 >> wt ; 
		u1-- ; u2-- ;
		graph[u1][u2] = wt ; 
	}

	shortestPath(graph , V , E ) ; 

	return 0 ; 
}