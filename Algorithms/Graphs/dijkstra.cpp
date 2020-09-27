/*Given a graph and a source vertex in graph, find shortest paths from source to all 
vertices in the given graph 
we use dijkstra algo . It is based on greedy algorithm 
Dijkstra can be used for both directed and undirected graph 

time : O(E Logv) , space : O(v + E) , not sure about space complexity 

input : 
6 9    // 6 is the no of nodes and 9 is the no of edges 
0 1 4
0 5 2
1 2 5
1 5 1
2 5 8
2 4 3
2 3 6
5 4 10
3 4 5
0       // 0 is the source vertesx 

output : 
Printing shortest path
0 -> 0
1 -> 3
2 -> 8
3 -> 14
4 -> 11
5 -> 2

*/

#include<bits/stdc++.h>
using namespace std ; 
#define ipair pair<int,int>
#define INF 1000000000



void shortestPath(vector<ipair> g[] , int V , int src ) {
	vector<int> dis(V , INF ) ; 
	vector<bool>sptSet(V) ; 
	priority_queue<ipair , vector<ipair> , greater<ipair >> pq ; 
	// ipair = > { weight , vertex }
	pq.push({0 , src }) ; 
	dis[src] = 0 ; 
	int u , v , wt ; 
	while (!pq.empty()) {
		u = pq.top().second ; 
		pq.pop() ; 
		sptSet[u] = true ; 
		for (ipair & x : g[u]) {
			v = x.first ;  wt = x.second ; 
			if (sptSet[v] == false &&  dis[v] > dis[u] + wt) {
				dis[v] = dis[u] + wt ; 
				pq.push({dis[v] , v }) ; 
			}
		}
	}
	//  printing shortest path from source to all other nodes 
	cout << "Printing shortest path " << endl; 
	for (int i = 0 ; i < V ; ++i ) {
		cout << i << " -> "  << dis[i] << endl; 
	}
}


int main () {
	int V, E ; 
	cin >>V >> E ; 
	vector<ipair > g[V] ;  int u1 , u2 , wt ; 
	for(int i = 0 ;i < E ; ++i ) {
		cin >> u1 >> u2 >> wt ; 
		// ipair = > { vertex , weight }
		g[u1].push_back({u2 , wt}) ; 
		g[u2].push_back({u1 , wt}) ; // comment this line for directed graph 
	}
	int  src ; cin >> src ; 
	shortestPath(g , V , src ) ; 
	return 0 ; 
}



