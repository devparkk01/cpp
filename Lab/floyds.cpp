#include<iostream>
using namespace std ; 

void floyds (int n , int ** A , int ** path  ) {
    for (int i = 1 ; i <= n ; ++i) {
        for (int j = 1 ; j <= n ; ++j ) {
            path[i][j] = A[i][j] ;    // initializing path matrix
        }
    }

    for ( int k = 1 ; k <= n ; ++k) {
        for (int i = 1 ; i <= n ; ++i) {
            for (int j = 1 ; j <= n ; ++j ) {
                path[i][j] = min (path[i][j] , (path[i][k] + path[k][j])) ; 
            }
        }
    }
}

int min (int a , int b) {
    if ( a < b ) 
        return a ; 
    else
        return b ; 
}


int main()
{
    int n ; 
    cout << "Enter no of vertices  : " << endl ;
    cin >> n ; 
    int ** A = new int *[n+1] ; 
    int ** path = new int *[n+1] ; 
    cout << "Enter matrix : " << endl  ; 
    for (int i = 1 ; i <=n ; ++i) {
        A[i] = new int [n+1] ; 
        path[i] = new int [n+1] ; 
        for (int j = 1 ; j <= n ; ++j) {
            cin >> A[i][j] ; 
        }
    }

    int a , b ; 
    cout << "Enter  source vertex : " << endl ; 
    cin >> a ; 
    cout << "Enter destination vertex : " << endl ; 
    cin >> b ; 

    floyds(n , A , path) ; 
    cout << "Shortest path from " << a << " to " << b << " is " << path[a][b] << endl ; 

    return 0 ; 
}