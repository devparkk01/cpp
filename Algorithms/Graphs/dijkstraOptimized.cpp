
/* Here is the optimized solution of dijkstra using priority queue . for knowing the difference
see the previous unoptimized implementation .
time and space complexity remains same .


*/

#include<bits/stdc++.h>
using namespace std ;
#define ip pair<int,int>
#define INF 1000000000


void shortestPath(vector<ip>g[] , int V , int src ) {
	vector<int>dist(V  , INF) ;
	bool sptSet[V] = {false } ; // to keep track of nodes for which we have found final
	// shortest path ( or those nodes which have been included in spt )
	priority_queue<ip , vector<ip> , greater<ip>> pq ; // it's a min heap

	dist[src] = 0 ;
	pq.push({dist[src] , src});

	int u , v , wt ;
	while (!pq.empty()) {
		u = pq.top().second ;
		pq.pop() ;
		if ( sptSet[u])  continue ; // if true then it means we have
		// already found shortest path for this node .  therefore skip it .

		// else , include it in the sptSet , since now we have found shortest path for this node .
		sptSet[u] = true ;

		for (ip &x  : g[u] ) {
			v = x.first ;  wt = x.second ;
			// if we haven't found shortest path for node v and there is a shorter path from source to v via u .
			if ( sptSet[v] == false  && dist[v] > dist[u] +  wt ) {
				dist[v] = dist[u] + wt ;
				pq.push({dist[v] , v }) ;
			}
		}
	}
	cout << "Printing shortest path " << endl;
	for (int i = 0 ; i < V ; ++i ) {
		cout << i << " -> "  << dist[i] << endl;
	}

}


int main () {
	int V, E ;
	cin >> V >> E ;
	vector<ip> g[V] ;  int u1 , u2 , wt ;
	for (int i = 0 ; i < E ; ++i ) {
		cin >> u1 >> u2 >> wt ;
		// ip = > { vertex , weight }
		g[u1].push_back({u2 , wt}) ;
		g[u2].push_back({u1 , wt}) ; // comment this line for directed graph
	}
	int  src ; cin >> src ;
	shortestPath(g , V , src ) ;
	return 0 ;
}



