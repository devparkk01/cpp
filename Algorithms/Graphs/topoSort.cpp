// Given a Directed Graph. Find any Topological Sorting of that Graph.
/* This approach is based on dfs .
time : O(V+E) , space : O(V)
*/

void topoSortUtil (vector<int>adj[] ,vector<bool>&visited,vector<int>&res,int u ) {
    visited[u] = true ;
    for(int x : adj[u]) {
        if (!visited[x]) {
            topoSortUtil(adj , visited , res , x ) ; 
        }
    }
    res.push_back(u) ;
}


vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool>visited(V) ;
    vector<int>res ; res.reserve(V) ; 
    for(int u = 0 ;u < V ; ++u ) {
        if ( !visited[u]) {
            topoSortUtil(adj , visited , res , u ) ; 
        }
    }
    reverse(res.begin() , res.end() ) ; 
    return res ; 
 
}
