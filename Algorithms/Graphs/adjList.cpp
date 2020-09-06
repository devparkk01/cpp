// adjacency list representation of the graph

#include<bits/stdc++.h>
using namespace std ; 

void print(vector<int> adj[] , int v ){
	for(int i = 0 ;i < v ; ++i ) {
		cout << i  ; 
		for(int x : adj[i]) {
			cout << "-> " << x ; 
		}
		cout << endl; 
	}
}

void add_edge (vector<int> adj[] , int u1 , int u2) {
	adj[u1].push_back(u2) ; 
	adj[u2].push_back(u1) ; 
}


signed main (){
	int v , e ; 
	cin >> v >> e ;
	vector<int > adj[v] ;
	int u1, u2  ;
	for(int i = 0 ; i < e ; ++i ) {
		cin >> u1 >> u2 ; 
		add_edge(adj , u1, u2) ; 
	}
	print(adj , v) ;

	return 0 ; 
}