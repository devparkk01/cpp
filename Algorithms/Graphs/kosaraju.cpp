/*Given a graph with V nodes and E directed edges. Your task is to complete the function 
kosaraju() which returns an integer denoting the number of strongly connected components in 
the graph.

time : O(V+ E) 
*/
#include<bits/stdc++.h>
using namespace std ; 

void dfs1 (vector<int>adj[] , vector<bool>&visited , stack<int>&stk , int u ) {
	visited[u] = true ; 
	for(int v : adj[u]) {
		if (!visited[v]) {
			dfs1(adj , visited,  stk , v ) ; 
		}
	}
	stk.push(u) ; 
}

void reverse(vector<int>rev[], vector<int>adj[] , int V ) {
	for(int u = 0 ; u < V; ++u) {
		for(int v: adj[u]) {
			rev[v].push_back(u) ; 
		}
	}
}

void dfs2 (vector<int>rev[] , vector<bool>&visited , int u ) {
	visited[u] = true ;
	cout << u << " " ; // printing components 
	for(int v : rev[u]) {
		if  (!visited[v]) {
			dfs2(rev , visited , v ) ; 
		}
	}
}

int kosaraju (vector<int>adj[] , int V ) {
	// 1st step,perform dfs traversals from every node.push node to the stack before returning.
	vector<bool>visited(V) ;
	stack<int>stk ; 
	for(int u = 0 ; u < V ; ++u ) {
		if (!visited[u]) {
			dfs1(adj , visited, stk , u );  
		}
	}
	// 2nd step,find the transpose of the graph 
	vector<int>rev[V] ; 
	reverse(rev , adj , V) ; 
	visited = vector<bool>(V) ; 

	// 3rd step,pop nodes one by one from stack and again do dfs on reversed graph . 
	int count = 0 ; int u ; 
	while (!stk.empty()) {
		u = stk.top() ; stk.pop() ; 
		if (!visited[u]) {
			count++ ; 
			dfs2(rev , visited , u );
			cout << endl; // for printing components 
		}
	}
	cout << "Total no of strongly connected components : " ;  
	return count ; 

}
signed main () {
	int V = 8 ;
	vector<int>adj[V] ;
	adj[0].push_back(1);
	adj[1].push_back(2);
	adj[2].push_back(0);
	adj[2].push_back(3);
	adj[3].push_back(4);
	adj[4].push_back(5);
	adj[4].push_back(7);
	adj[5].push_back(6);
	adj[6].push_back(4);
	adj[6].push_back(7);

	cout <<  kosaraju(adj , V)  ; 

	return 0 ; 
}