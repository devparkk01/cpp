/*List of edges will be given , find if it contains negative edge weight cycle . if it doesn't
then print the shortest distances from source node . 
time : O(E*V) , space : O(V)
*/
#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
struct edge {
    int u ; int v ; int wt ; 
    edge(int u , int v , int wt) {
        this->u = u ; this->v = v ; this->wt = wt ; 
    }
}; 

void negWtCycle(vector<edge>&edgeList , int V , int E ) {
    vector<int>dist(V, INF) ; 
    // assume 0 to be the source node 
    dist[0] = 0 ; 
    int u , v , wt ; bool updated = false ; 
    for(int i = 0 ; i < V-1 ; ++i ) {
    	updated = false ; 
        for(int e = 0 ; e < E ; ++e ) {
            u = edgeList[e].u ; v = edgeList[e].v ; wt = edgeList[e].wt ; 
            // if there is a path from source to u
            // if there is a shorter path from src to v via u 
            if ( dist[u] != INF && dist[v] > dist[u] + wt ) {
                dist[v] = dist[u]  + wt ;
                updated = true ;  
            }
        }
        if (updated == false ) break ; // break if we didn't do any updation 
    }
    for(int e = 0 ;e < E ; ++e ) {
        u = edgeList[e].u ; v = edgeList[e].v ; wt = edgeList[e].wt ; 
        if ( dist[u] != INF && dist[v] > dist[u] + wt ) {
            cout << "Yes, contains a cycle " ; // contains negative edge weight cycle 
            return ; 
        }
    }
    //  printing shortest distances 
    cout << "Doesnot contain cycle " << endl  ; 
    for (int i = 0 ; i < V ; ++i ) {
    	cout << dist[i] << " "; 
    }
}

int main()
{
	int V, E ; 
    cin >> V >> E ; 
    vector<edge>edgeList(E , {0 ,0 , 0 }) ; 
    int u , v , wt ;
    
    for(int i = 0 ; i < E ; ++i ) {
        cin >> u >> v >> wt ; 
        edgeList[i] = edge(u , v , wt ) ; 
    }
    negWtCycle(edgeList , V, E )  ; 
    
	return 0;
}

/*
4 5
0 1 5
0 2 -4
1 2 3
2 3 1
3 0 2
contains a cycle 

*/