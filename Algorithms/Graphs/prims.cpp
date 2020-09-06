/*Given a weighted, undirected and connected graph.find the sum of weights of the edges considered 
in mst
graph :  V =3 , E = 3 
1 2 5 
2 3 3
1 3 1
ans : 4
3-2->3
1-3->1

time : O(V*V) , space : O(V)
 */

#include<bits/stdc++.h>
using namespace std ; 
// V is the no of nodes , key stores the key value , and mstSet stores info about the nodes 
// included in bst 
int minKey (int V , vector<int> &key , vector<bool> &mstSet ) {
	int min = INT_MAX , min_vertex ;
	for(int v = 0 ; v < V ; ++v ) {
		if ( mstSet[v] == false && key[v] < min ) {
			min = key[v] ; min_vertex = v;  
		}
	}
	return min_vertex ; 
}

void printMst (int V , vector<int> &parent , vector<vector<int>> &graph) {
	for(int i = 1 ; i < V ; ++i ) {
		cout << parent[i]+1 << "-" << i+1 << "->" << graph[parent[i]][i] << endl; 
	}
}


void primMst(int V , vector<vector<int>> &graph ) {
	vector<int>key(V , INT_MAX) ;
	vector<bool>mstSet (V ) ; 
	vector<int> parent(V) ; 

	key[0] = 0 ;
	parent[0] = -1 ; 
	// mst contains v vertices. we will run this v-1 times , this is because the last 
	// vertex will contain 
	for (int count = 0 ; count < V-1 ; ++count ) {
		int u = minKey (V , key , mstSet) ; 
		mstSet[u] = true ; 
		for(int v = 0 ; v < V ; ++v ) {
			if ( graph[u][v] != INT_MAX && mstSet[v] == false && key[v] > graph[u][v] ) {
				key[v] = graph[u][v] ; 
				parent[v] = u ; 
			}
		}
	}
	cout << "Sum of weights in MST : " <<  accumulate(key.begin(),key.end(),0 ) << endl ;
	printMst(V , parent , graph) ;

}


signed main () {
	int V , E  ; cin >>V >> E  ;
	vector<vector<int>> graph(V , vector<int>( V , INT_MAX ))  ; 
	int i = 0 ;   int u , v , w ;
	while (i++ < E ) {
		cin >> u >> v >> w ; 
		u-- ; v-- ; 
		graph[u][v] = w ;
		graph[v][u] = w ; 
	}
	primMst(V , graph) ;

	return 0 ; 
}


