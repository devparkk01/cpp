#include<iostream>
using namespace std  ; 


void dfs (int n , int ** adj , int * visited  , int v  ) {
    visited[v] = 1 ; 
    for (int i = 1 ; i <= n ; ++i) {
        if ( adj[v][i] == 1) {
            if ( visited[i] == 0) {
                dfs(n ,  adj ,  visited , i ) ; 
            }
        } 
    }
}

int isConnected (int **adj , int n ) {
    int *visited = new int[n+1] ; 
    for (int i = 1 ; i <= n ; ++i ) {
        for (int j = 1 ; j <= n ; ++j ){
            visited[j] = 0 ; 
        }
        dfs (n , adj , visited , i ) ;
    
        for (int j = 1 ; j <= n ; ++j) {
            if (visited[j] == 0 ) {
                return 0 ;
            }
        }
    
    }
    return 1;  

}


int main () {
    int n ; 
    cout << "Enter the no of vertex : " << endl  ; 
    cin >> n ;
    cout << "Enter adjacency matrix : " << endl; 
    int ** adj = new int *[n+1] ; 
    for (int i = 1 ; i <= n ; ++i ) {
        adj[i] = new int [n+1] ;
        for (int j = 1 ; j <= n ; ++j ) {
            cin >> adj[i][j] ; 
        }
    }
    if (isConnected(adj , n )) {
        cout << "Graph is connected  :  " << endl ;
    }
    else {
        cout << "Graph is not connected  : "  << endl ; 
    }

    return 0 ; 

}
