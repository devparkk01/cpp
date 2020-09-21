/*Given an undirected graph , print all bridges in this graph . 

time : O(V + E) based on tarjans algo 
*/

#include<bits/stdc++.h>
using namespace std ; 


void bridgeUtil (vector<int>adj[],bool visited[],int disc[],int low[],int u,int parent,int &timer ) {
	visited[u] = true ; 
	disc[u] = low[u] = ++timer ;

	for(int &v : adj[u]) { // edge being considered is u-v 
		if (visited[v]) {
			if (v == parent ) continue ;// ignore if it's the parent 
			else // we found an ancestor through the back edge 
				low[u] = min(low[u] , disc[v]) ; 
		}
		else {
			bridgeUtil(adj , visited , disc , low , v , u, timer )  ;
			// check if the subtree rooted with v has a connection to one of the 
			//  ancestors of u 
			low[u] = min(low[u] , low[v]) ;
			// condition for the edge u-v to be a bridge 
			if ( low[v] > disc[u]) 
				cout << u << "-" << v << endl ; 
		}
	}

}

void findBridge(vector<int>adj[] , int V) {
	bool visited[V] = {false } ; 
	int disc[V] ; 
	int low[V] ;
	int timer = 0 ; 
	int parent = -1 ; 

	for(int u = 0 ; u < V ; ++u ) {
		if (!visited[u]) {
			bridgeUtil(adj , visited , disc , low , u , parent , timer ) ; 
		}
	}

}
void addEdge(vector<int>adj[], int u , int v ) {
	adj[u].push_back(v) ;
	adj[v].push_back(u) ; 
}


signed main() {
	int V= 5 , E = 5 ; 
	vector<int>adj[V] ; 
	int u , v ; 
	for(int i = 0 ; i < E ; ++i ) {
		cin >> u >> v ; 
		addEdge(adj , u , v ) ; 
	}
	findBridge(adj, V) ; 

	return 0 ; 
}