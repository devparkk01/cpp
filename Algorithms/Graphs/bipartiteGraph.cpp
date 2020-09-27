/*Given a graph , check whether it is a bipartite graph or not . 

idea : 
we will use breadth first search along with graph coloring for solving this type of problem .

using adjacency List : time :  O(V+E) , space : O(V)
using adjacency matrix : time : O(V^2) , space : O(V)

*/
#include<bits/stdc++.h>
using namespace std ; 

bool bipartiteUtil(vector<vector<int>>&adj , int V , int u , vector<int>&color ) {
	queue<int>q ; 
	q.push(u) ; 
	color[u] = 0 ; 
	int v , c ; 
	while(!q.empty()) {
		v = q.front() ; q.pop() ;
		c = color[v] ;
		for(int i = 0 ;i < V ; ++i ) {
			if ( adj[v][i]){
				if ( color[i] == c)
					return false ; 
				else if (color[i] == -1 ) {
					color[i] = 1-c ; 
					q.push(i) ; 
				}
			}
		}
	}
	return true ; 
}


bool isBipartite(vector<vector<int>>&adj , int V ) {
	vector<int>color(V , -1 ) ; 
	for(int i = 0 ; i < V ; ++i ) {
		if ( color[i]== -1) {
			if (bipartiteUtil(adj , V , i , color ) == false  )
				return false; 
		}
	}
	return true ; 
}

signed main () {
	int V = 4; 
	vector<vector<int>>adj = {{0, 1, 0, 1}, 
        {1, 0, 1, 0}, 
        {0, 1, 0, 1}, 
        {1, 0, 1, 0} 
    }; 
    cout << isBipartite(adj , V) << endl; 
    return 0 ; 

}