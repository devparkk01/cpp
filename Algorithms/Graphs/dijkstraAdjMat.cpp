/*Given a graph of V nodes represented in the form of the adjacency matrix. The task is to find
 the shortest distance of all the vertex's from the source vertex.

time : O(V*V) , space : O(V)
*/

#include<bits/stdc++.h>
using namespace std ; 



int minDist (int V ,vector<int> &dist , vector<bool> & sptSet   ){
    int min  = INT_MAX ; int min_vertex ;
    for(int v = 0 ; v < V; ++v ) {
        if (!sptSet[v] && min > dist[v]) {
            min = dist[v] ;
            min_vertex = v ; 
        }
    }
    return min_vertex ; 
}


vector <int> dijkstra(vector<vector<int>> &g, int src, int V)
{
    vector<int>dist(V , INT_MAX) ; 
    vector<bool>sptSet(V) ; 
    
    dist[src] = 0  ; 
    for (int count = 0 ; count  < V-1 ; ++count ) {
        int u = minDist(V , dist , sptSet) ;
        sptSet[u] = true ; 
        for(int v = 0 ; v < V ; ++v ) {
            if (g[u][v] && sptSet[v] == false && dist[u] != INT_MAX && dist[v] > dist[u] + g[u][v]) {
                dist[v] = dist[u] + g[u][v] ; 
            }
        }
      
    }
    return dist ; 
}


signed main () {
    // fastio ; 
    int V, E ; cin >> V >> E ; 

    vector<vector<int >>graph(V , vector<int>(V)) ; 
    int u1 , u2 , wt ; 
    for(int i = 0 ;i < E ; ++i ) {
        cin >> u1  >> u2 >> wt ; 
        u1-- ; u2-- ;
        graph[u1][u2] = wt ; 
    }

    vector<int> res = dijkstra(graph , 0 , V) ; 
    for(int i = 0 ;i < V ; ++i ) {
        cout << res[i] << " " ; 
    }

    return 0 ; 
}