/*Given an undirected graph and an edge, the task is to find if the given edge is a 
bridge in graph, i.e., removing the edge disconnects the graph.
for a disconnected undirected graph,  a bridge edge is an edge removing which 
increases number of components in the graph .

time : O(V+E) , space : O(V)
https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1 

approach : 
we will be given adjacency list and the edge to be removed . let the edge connects s and e . 
first we will remove this edge , then we will call dfs from one of these two nodes. If we can still 
visit the other node that means this is not a bridge edge(because graph didn't get disconnected) , 
if we can't visit the other  node that means this is a bridge edge .
*/

void dfs (list<int>adj[],vector<bool>&visited , int i ) {
    visited[i] = true ; 
    for(int v : adj[i]) {
        if (!(visited[v]))
            dfs(adj , visited , v) ; 
    }
}


// adjacency list is given , V is the no of nodes , s-e denotes the edge that will be removed 
bool isBridge(list<int> adj[], int V, int s, int e) {
    vector<bool>visited(V) ;
    // remove this edge 
    adj[s].remove(e) ;
    adj[e].remove(s) ; 
    // call dfs from one of these two nodes 
    dfs(adj , visited , s) ;
    // check if we could visit the other node 
    if (visited[e]) return false;  
    return true ; 
    
}
