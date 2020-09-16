/*Given an undirected graph , print all articulation points(cut vertices ) in this graph . 

time : O(V + E) based on tarjans algo 
*/


#include<bits/stdc++.h>
using namespace std ; 

void apUtil (vector<int>adj[] ,bool visited[], int low[] , int disc[] ,bool ap[] , int u , int parent , int &timer) {
	int children = 0 ; // for counting the children 
	visited[u] = true; 

	disc[u] = low[u] = ++timer ; 
	for(int &v : adj[u]) {
		if (visited[v] ) {
			if (v == parent ) continue ; // ignore if it's the parent 
			else // this means we found an ancestor through back edge  , v is the ancestor node
				low[u] = min(low[u] , disc[v]) ; 
			// finds the ancestor with the least discovery time 
		}
		else if (!visited[v]) {
			children++ ; 
			apUtil(adj , visited, low , disc , ap , v , u , timer) ;
            // Check if the subtree rooted with v has a connection to 
            // one of the ancestors of u 
			low[u] = min(low[u] , low[v]) ;

		   	// u is an articulation point in following cases 
			//  condition 2  u is root of DFS tree and has two or more children subgraph
			if (parent == -1 && children > 1 )
				ap[u] = true ;
			//  condition 1 If u is not root and low value of one of its child is more 
            // than or equal to discovery value of u. 
			if ( parent != -1 && disc[u] <= low[v]) 
				ap[u] = true ; 
		}
	}
}

void findAp(vector<int>adj[] , int V) {
	bool visited[V] = {false } ;
	int low[V] ; 
	// low[i] is the least discovery time of the node that can be reached from i through
	// a back edge . 
	int disc[V] ;  // discovery time of the node 
	bool ap[V] = {false} ;
	int timer = 0 ;
	int parent = -1 ; 
	
	for(int u = 0 ; u < V ; ++u ) {
		if (!visited[u]) {
			apUtil(adj , visited , low , disc ,ap , u , parent , timer) ; 
		}
	}

	//  printing articulation points 
	for(int u = 0 ; u < V ; ++u ) {
		if ( ap[u]) 
			cout << u << " " ; 
	}

}


void addEdge(vector<int>adj[], int u , int v ) {
	adj[u].push_back(v) ;
	adj[v].push_back(u) ; 
}



signed main () {

	int V =  13 , E = 15 ; 
	vector<int>adj[V] ; 
	addEdge(adj , 0  , 1 ) ; 
	addEdge(adj , 0  , 6 ) ; 
	addEdge(adj , 0  , 5 ) ; 
	addEdge(adj , 0  , 4 ) ; 
	addEdge(adj , 0  , 1 ) ; 
	addEdge(adj , 1  , 2 ) ; 
	addEdge(adj , 1  , 3 ) ; 
	addEdge(adj , 2  , 3 ) ; 
	addEdge(adj , 5  , 6 ) ; 
	addEdge(adj , 4  , 7 ) ; 
	addEdge(adj , 4  , 8 ) ; 
	addEdge(adj , 4  , 11 ) ; 
	addEdge(adj , 4  , 9 ) ; 
	addEdge(adj , 9 , 10 ) ; 
	addEdge(adj , 11 , 12 ) ; 
	findAp(adj , V) ; 
	return 0 ; 
}