/*implementation of kruskals algo for finding mst . 
It's also a greedy algorithm . 

time : O(ElogE + ElogV)

input : 
V = 4 , E = 5 
0 1 10
0 2 6
0 3 5
1 3 15
2 3 4
output : 
2 3 4
0 3 5
0 1 10

*/


#include<bits/stdc++.h>
using namespace std ; 

struct Node {
	int parent ;
	int rank ;
};

struct Edge {
	int src ;
	int dest ;
	int wt ; 
};

bool compare (Edge &e1 , Edge &e2 ) {
	return e1.wt < e2.wt ;
}

void printGraph (vector<Edge > &graph  ) {
	for(Edge x : graph ) {
		cout << x.src << " " << x.dest << " " << x.wt << endl; 
  	}
}

int find(vector<Node> & subsets , int i ) {
	if ( subsets[i].parent == -1 ) 
		return i ;
	subsets[i].parent = find(subsets , subsets[i].parent ) ;
	return subsets[i].parent ; 
}


void Union(vector<Node> &subsets , int i , int j ) {
	int ip  = find(subsets , i) ;
	int jp  = find(subsets , j ) ;

	if (subsets[ip].rank < subsets[jp].rank ) {
		subsets[ip].parent = jp ; 
	}
	else if (subsets[ip].rank > subsets[jp].rank ) {
		subsets[jp].parent = ip ;
	}
	else {
		subsets[ip].parent = jp ;
		subsets[jp].rank++ ; 
	}
}

void kruskals( vector<Edge> &graph,int V, int E ) {
	sort(graph.begin() , graph.end() , compare ) ;

	vector<Node> subsets(V , {-1 , 0 }) ;
	vector<Edge> mst(V-1 , {0 , 0 , 0 }) ; 

	int count = 0 ; int e = 0 ;  
	int ip , jp ; 
	while (count < V-1 && e < E ) {
		ip = find(subsets , graph[e].src ) ;
		jp = find(subsets , graph[e].dest ) ;

		if (ip == jp ) {
			e++ ; continue ; 
		}

		Union(subsets ,ip , jp ) ; 
		mst[count] = graph[e] ; 
		count++ ; e++ ; 
	}
	printGraph(mst ) ; 
	
}

signed main () {
	int V ,E ; cin >>V >> E  ;
	vector<Edge>graph(E , {0, 0 ,0 }) ; 
	int src , dest, wt ; 
	for(int i = 0 ;i < E ; ++i ) {
		cin >>src >> dest >>wt ; 
		graph[i].src = src ;
		graph[i].dest = dest ; 
		graph[i].wt = wt ; 
	}

	kruskals(graph , V , E) ;
	// printGraph(graph) ; 
	return 0 ;
}
