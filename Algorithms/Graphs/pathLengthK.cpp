/*Given a graph, a source vertex in the graph and a number k,find if there is a simple path, of path 
length greater then or equal to k,(without any cycle) starting from a given source and 
ending at any other vertex. Source vertex should always be  0.
The graph can be directed or undirected .

time : O(n!)
*/


#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false ) ; cin.tie(NULL ) ; 
#define ipair pair<int, int >

void dfs(vector<ipair>adj[] , bool visited[] ,int u ,  int curLen , int k , bool &flag ) {
    if(flag == true) return;  // found the path , so don't do anything
    
    visited[u] = true ; 
    if ( curLen >= k ) {
        flag = true ; 
        visited[u] = false ; // backtrack
        return ; 
    }
    else {
        int v , l ; 
        for(ipair x : adj[u] ) {
            v = x.first ; l = x.second ; 
            if (!visited[v]) {
                dfs(adj , visited , v ,curLen + l  , k , flag  ) ; 
            }
        }
        //backtrack 
        visited[u] =  false ; 
    }
}

signed main()
{
    fastio ;
    int t;  cin >> t; 
    while (t-- ) {
        int V , E , k ; 
        cin >>V >> E >> k; 
        vector<ipair>adj[V] ; 
        int u, v ,l ;
        for(int i = 0; i < E ; ++i ) {
            cin >> u >> v >> l ; 
            adj[u].push_back({v , l}) ; 
            adj[v].push_back({u , l }); // if it's an undirected graph 
        }
        int curLen = 0 ; bool flag = false ;
        bool visited[V] = {false } ; 
        dfs(adj , visited , 0 , curLen , k , flag ) ;
        cout << flag << endl; 
        
    }
	return 0;
}