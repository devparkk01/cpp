#include<iostream>
using namespace std ; 

void topologicalSorting (int ** adj ,  int n ) {
    int * indegree = new int [n+1] ; 
    int * check = new int[n+1] ; 
    int * ts = new int[n+1] ; 

    int i = 1 ; 
    while ( i <= n ) {    // initializing indegree
        indegree[i] = 0  ; 
        for (int j = 1 ; j <= n ; ++j) {
            if (adj[j][i] == 1) 
                indegree[i]++ ; 
        }
        i++ ; 
    }

    for (int i = 1; i <= n ; ++i)       // initializing check
        check[i] = 0 ; 

    int k = 1 ;       // k is for indexing of ts
    while (true) {
        int i = 1 ; 
        while ( i <= n ) {
            if (check[i] == 0  &&  indegree[i] == 0 )
                break ; 
            i++ ;
        }
        if ( i > n ) 
            break ;     // comes out of the outermost while loop

        ts[k]  = i ; 
        check[i] = 1; 
        for ( int j = 1  ; j <= n ; ++j ) {
            if ( adj[i][j] == 1 ) 
                indegree[j]-- ; 
        }

        k++ ; 

    }
    if (k < n+1 ) 
        cout <<  "Topological sequence does not exist: " << endl  ;
    else {
        cout << "Topological sequence exists : " << endl ; 
        for ( int i = 1 ; i <= n ; ++i) 
            cout << ts[i] << " " ; 
    }

}


int main() {
    int n ; 
    cout << "Enter no of vertices : " << endl ; 
    cin >> n ; 
    int ** adj = new int*[n+1] ; 
    cout << "Enter adjacency matrix : "  << endl ; 
    for (int i = 1 ; i <= n ; ++i ) {
        adj[i] = new int[n+1] ; 
        for (int j = 1 ; j <= n ; ++j) {
            cin >> adj[i][j] ; 
        }
    }
    topologicalSorting(adj , n ) ; 

    return 0 ; 
}