/*Given a Directed Graph. Check whether it contains any cycle or not. */

// time : O(v + E ) , space : O(v)

bool isCyclicUtil (vector<int>adj[] ,vector<bool>&visited , vector<bool>&recStack ,int u ) {
    visited[u] = true ; 
    recStack[u] = true ; 
    for (int x : adj[u]) {
        if (!visited[x]) {
            if ( isCyclicUtil(adj , visited , recStack , x ))
                return true ; 
        }
        else if ( visited[x] && recStack[x]){
            return true ; 
        }
    }
    recStack[u] = false ; 
    return false ; 
}


bool isCyclic(int V, vector<int> adj[])
{
    vector<bool>visited(V) ; 
    vector<bool>recStack(V) ;
    
    for(int u = 0 ; u < V ; ++u ) {
        if (!visited[u]) {
            if (isCyclicUtil (adj , visited , recStack , u ))
                return true ; 
        }
    }
    return false ; 
}