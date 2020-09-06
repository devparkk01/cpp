/*The problem is to find shortest distances between every pair of vertices in a given edge
weighted directed Graph. The Graph is represented as Adjancency Matrix, 
and the Matrix denotes the weight of the edegs (if it exists) else INF (1e7).

time : O(V*V*V) , space : O(V*V) 
*/


#include<bits/stdc++.h>
using namespace std ; 
#define INF 100000

void floydWarshall(int V , vector<vector<int>> &graph ) {
	int dist[V][V] ; // output matrix (shortest path matrix )
	// initialize the output matrix same as input matrix 
	for(int i = 0 ;i < V ; ++i ) {
		for(int j = 0 ; j < V; ++j ) {
			dist[i][j] = graph[i][j]  ;
		}
	}
	// find all pairs shortest path by trying all possible paths 
	for(int k = 0 ; k < V ; ++k ) {
		for(int i = 0 ;i < V; ++i ) {
			for (int j= 0 ; j < V ; ++j ) {
				// SKIP if k is unreachable from i or j is unreachable from k 
				if ( dist[i][k] == INF || dist[k][j] == INF ) 
					continue ; 
				else // update dist[i][j]
					dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]) ; 
			}
		}
	}

	//  printing the solution 
	for(int i = 0 ;i < V; ++i ) {
		for(int j = 0 ; j < V ; ++j ) {
			if ( dist[i][j] == INF) 
				cout << "INF" << " " ; 
			else 
				cout << dist[i][j] << " " ; 
		}
		cout << endl;  
	}

}

signed main () {
	int V = 6 ; 
	vector<vector<int>> graph = {
   						{0, 1, 4, INF, INF, INF},
						{INF, 0, 4, 2, 7, INF},
						{INF, INF, 0, 3, 4, INF},
						{INF, INF, INF, 0, INF, 4},
						{INF, INF, INF, 3, 0, INF},
						{INF, INF, INF, INF, 5, 0}
	                  } ; 

	floydWarshall(V , graph) ; 

	return 0 ; 

}
/*   output : 

0 1 4 3 8 7
INF 0 4 2 7 6
INF INF 0 3 4 7
INF INF INF 0 9 4
INF INF INF 3 0 7
INF INF INF 8 5 0

*/