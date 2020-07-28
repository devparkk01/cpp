#include<iostream>
#include<vector>

using namespace std; 
  
// Returns true if edge u-v is a valid edge to be 
// include in MST. An edge is valid if one end is 
// already included in MST and other is not in MST. 
bool isValidEdge(int u, int v, vector<bool> mst) 
{ 
   if (u == v) 
       return false; 
   if (mst[u] == false && mst[v] == false) 
        return false; 
   else if (mst[u] == true && mst[v] == true) 
        return false; 
   return true; 
} 
  
void primMST(int **cost , int n ) 
{   
    vector<bool> mst(n+1, false); 
  
    // Include first vertex in MST 
    mst[1] = true; 
  
    // Keep adding edges while number of included 
    // edges does not become V-1. 
    int edge_count = 0, mincost = 0; 
    while (edge_count < n - 1) { 
  
        // Find minimum weight valid edge.   
        int min = 0 , a = -1, b = -1; 
        for (int i = 1; i <= n; i++) { 
            for (int j = 1; j <= n; j++) {                
                if (cost[i][j] > min) { 
                    if (isValidEdge(i, j, mst)) { 
                        min = cost[i][j]; 
                        a = i; 
                        b = j; 
                    } 
                } 
            } 
        } 
        if (a != -1 && b != -1) { 
            printf("Edge %d:(%d, %d) cost: %d \n",  
                         edge_count++, a, b, min); 
            mincost = mincost + min; 
            mst[b] = mst[a] = true; 
        } 
    } 
    printf("\n Minimum cost= %d \n", mincost); 
} 
  
// driver program to test above function 
int main() 
{ 

    int n ; 
    cout << "Enter the no of vertices : " << endl; 
    cin >> n ; 
    cout << "Enter cost matrix : " << endl ; 
    int **cost = new int*[n+1] ;
    for (int i = 1 ;i <= n ; ++i ) {
        cost[i] = new int[n+1] ; 
        for (int j = 1 ;j <=n ;++j) {
            cin >> cost[i][j] ; 
        }
    }

  
    // Print the solution 
    primMST(cost, n); 
  
    return 0; 
}