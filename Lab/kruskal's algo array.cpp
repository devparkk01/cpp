#include<iostream>
using namespace std ;

int find(int arr[] , int u) 
{
    while (arr[u] != u ) 
    {
        u = arr[u] ; 
    }
    return u ; 
}

void Union(int arr[] , int u , int v ) 
{   
    int u_set = find(arr , u) ;
    int v_set = find(arr, v) ; 
    arr[u_set] = v_set ; 
}

void mst_kruskal ( int n , int ** cost ) 
{
    int min_cost = 0 ; 
    int edge_count = 0 ; 
    int * set = new int[n + 1 ] ; 
    int ** mst = new int * [n-1] ; 
    for (int i = 0 ; i< n-1 ; ++i) 
    {   mst[i] = new int[2] ; }

    for ( int i = 1 ; i<=n ; ++i ) 
    { set[i] = i ; }

    while ( edge_count < n-1 ) 
    {
        int min = 500 , U , V ; 
        for (int i = 1 ; i<=n ; ++i) 
        {
            for (int j = 1 ; j <= n ; ++j ) 
            {
                if (find(set , i) != find(set , j)  && cost[i][j] < min) 
                {
                    U = i ; 
                    V = j ; 
                    min = cost[i][j] ; 
                }
            }
        }
        if ( min != 500 ) {
            mst[edge_count][0] = U ; 
            mst[edge_count][1] = V ; 
            Union(set ,U , V) ; 
            min_cost += min ; 
            edge_count++ ; 
        }
        else {
            break ; 
        }

    }
    if (edge_count == n-1) 
    {
        for ( int i = 0 ; i < n-1 ; ++i) 
        {
            cout << mst[i][0] << "-->" << mst[i][1] << endl; 
        }
        cout << "Min cost : " << min_cost ; 
    }
    else 
    {
        cout << "Graph is not connected : " << endl ; 
    }
}


int main() 
{
    int n ;
    cout << "Enter no of vertices : " << endl  ; 
    cin >> n ; 
    int **cost = new int *[n + 1 ] ; 
    for ( int i = 1 ; i<=n ; ++i) 
    {
        cost[i] = new int[n + 1] ; 
        for ( int j = 1 ;j <= n ; ++j ) 
        {
            cin >> cost[i][j] ; 
        }
    }

    mst_kruskal( n , cost ) ;
    return 0 ; 

    
}