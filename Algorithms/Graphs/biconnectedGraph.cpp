/* Given a directed graph, check whether it is Biconnected or not. 
In graph theory , a biconnected graph is a connected and 'non separable' graph, meaning that 
if any one vertex were to be removed , the graph will remain connected . Therefore a biconneted 
graph has no articulation point . 
in short , connected having no articulation point .
time : O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define endl '\n'

bool hasArticulationPoint(vector<int>adj[] , bool visited[] , int disc[] , int low[] , int u , int parent , int &timer ) {
    int children = 0 ;

    visited[u] = true ;
    disc[u] = low[u] = ++timer ;
    
    for(int &v : adj[u]) {
        if (visited[v]) {
            if (v == parent )  continue ; 
            else 
                low[u] = min(low[u] , disc[v]) ;
        }
        else {
            children++ ; 
            // if subtree rooted with v has an articulation point 
            if ( hasArticulationPoint(adj , visited, disc, low , v , u , timer ))
                return true ; 

            low[u] = min(low[u] , low[v]) ;
            
            //  checking if u is an articulation point 
            if(parent == -1 && children > 1 )
                return true ;
                
            if (parent != -1 && low[v] >= disc[u]) 
                return true; 
        }
    }
    return false ; // u is not an articulation point, returning false to its parent . 
}



bool isBi (vector<int>adj[] ,int V) {
    bool visited[V] = {false} ;
    int disc[V] ; int low[V] ;
    int parent = -1 ; 
    int timer = 0 ;
    
    if (hasArticulationPoint(adj , visited , disc, low , 0 , parent ,timer))
        return false; 
    
    for(int u = 0 ;u < V ; ++u ) {
        if (!visited[u]) 
            return false ; 
    }
    return true ; 
}


int main()
{
    fastio ; 
    int t;  cin >>t ; 
    while (t-- ) {
        int V, E ; cin >> V >> E ; 
        vector<int>adj[V] ; 
        int u , v ; 
        for(int i = 0 ; i < E ; ++i) {
            cin >> u >> v ; 
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }
        cout << isBi(adj , V) << endl; 
    }
	return 0;
}