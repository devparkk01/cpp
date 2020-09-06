/*Given a Undirected Graph. Check whether it contains a cycle or not. */

// time : O(v + E ) , space : O(v)


bool isCyclicUtil (vector<int> g[] , vector<bool> &visited ,  int u , int p ) {
    // u is the current node and p is u's parent node 
    visited[u] = true ; 
    for (int node : g[u]) {
        if (!visited[node]) {
            if (isCyclicUtil (g , visited , node , u ))
                return true ; 
        }
        else if ( visited[node] && node != p ) // check for back edge 
            return true ; // this is a back edge 
    }
    return false ; 
}

bool isCyclic(vector<int> g[], int V)
{
    vector<bool>visited(V ) ; 
    for(int u = 0 ; u < V ; ++u ) {
        if (!visited[u]) {
            if ( isCyclicUtil(g , visited ,u , -1))
                return true ; 
        }
    }
    return false ; 
   
}