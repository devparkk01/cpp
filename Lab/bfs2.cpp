#include<iostream>
#include<queue>

using namespace std ; 

void bfs (int** adj , int n , int source  ) {
    queue<int> q ; 
    int * visited = new int [n+1] ;
    for (int i = 1 ; i <= n ; ++i ) {
        visited[i] = 0 ; 
    }
    visited[source] = 1 ; 
    q.push(source) ; 

    while (! q.empty() ) {
        auto front_element = q.front() ;
        cout << front_element << " "  ; 
        q.pop() ; 
        for (int i = 1 ; i <= n ; ++i ) {
            if (adj[front_element][i] == 1 ) {
                if (visited[i] == 0 ) {
                    q.push(i) ; 
                    visited[i] = 1 ; 
                }
            }
        }
    }

}

int main () {
    int n ; 
    cout << "Enter the no of vertex : " << endl ; 
    cin >> n ;
    cout << "Enter the adjacency matrix : " << endl ;
    int ** adj = new int *[n+1] ; 
    for (int i = 1 ; i<= n ; ++i ) {
        adj[i] = new int [n+1] ; 
        for ( int j = 1 ; j <= n ; ++j) {
            cin >> adj[i][j] ; 
        }
    }
    int source ; 
    cout << "Enter the source vertex : " << endl ; 
    cin >> source ; 
    
    bfs (adj , n , source ) ;

    return 0 ; 

}


