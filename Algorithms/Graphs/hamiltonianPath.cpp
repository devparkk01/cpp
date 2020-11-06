/*A Hamiltonian path, is a path in an undirected or directed graph that visits each vertex exactly
once. Given an undirected graph  the task is to check if a Hamiltonian path is present in 
it or not.
*/


#include<bits/stdc++.h>
using namespace std;

void dfs (vector<int>adj[],bool visited[],vector<int>&path,int u,int N,bool &flag) {
    if (flag == true )  return ; 
    
    visited[u] = true ; 
    path.push_back(u) ; 
    if ( path.size() == N ) {
        flag = true ; 
        visited[u] = false ;
        path.pop_back() ; 
    }
    else {
        for(int v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, visited,path , v, N , flag) ; 
            }
        }
        visited[u] = false ; 
        path.pop_back() ; 
    }
    
}

int main()
{
	//code
	int t;  cin >> t ; 
	while (t-- ) {
	    int N , M ; cin >>N >> M ; 
	    vector<int>adj[N] ; int u , v ; 
	    for(int i= 0 ;i < M ; ++i ) {
	        cin >> u >> v  ;
	        u-- ; v-- ; 
	        adj[u].push_back(v) ; 
	        adj[v].push_back(u ) ; 
	    }
        bool visited[N] = {false} ;
        vector<int>path ; path.reserve(N) ; 
	    bool flag = false ;  
	    for(int i= 0 ; i < N ; ++i) {
	        dfs(adj , visited , path , i , N , flag) ;
	        if ( flag == true ) { break ; }
	    }
	    cout << flag << endl; 
	}
	
	return 0;
}