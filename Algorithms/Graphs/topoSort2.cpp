// Given a Directed Graph. Find any Topological Sorting of that Graph.
/* This approach is based on bfs.  This is also known as kahn's algorithm.
time : O(V+E) , space : O(V)
*/


#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    // Calculate indegrees of all nodes/vertices
    vector<int>indegree(V);
    for(int u = 0 ; u < V; ++u){
        for(int &v : adj[u]) {
            indegree[v]++;
        }
    }

    // q stores those nodes whose indegrees are 0. That means these nodes do not have any dependency
    // on it, hence we can process them. 
    queue<int>q; 
    for(int u = 0; u < V ; ++u) {
        if (indegree[u] == 0) {
            q.push(u);
        }
    }
    // Stores final topological order.
    vector<int>topo; topo.reserve(V);

    
    while(!q.empty()) {
        int u = q.front(); q.pop(); 
        // push the nodes to the topo order.
        topo.push_back(u);

        // relax all the edges adjacent to u.
        for(int &v: adj[u]) {
            // when we relax, we decrease its indegree by 1.
            indegree[v]--;
            // if indegree becomes 0, that means this adjacent node does not have any dependency 
            // left, so we can push it safely to our queue(q).
            if(indegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topo;
    // if in case, this graph is not DAG, then in that case topo will not contain all vertices of 
    // the graph. Hence, this algorithm can be used to find if the graph contains a cycle. 
    // if it contains a cycle, then the total no vertices in topo will not be equal to V.
}