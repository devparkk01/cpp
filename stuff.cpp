#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false) ;cin.tie(NULL); cout.tie(NULL) ;

void dfs(vector<int>adj[] , vector<bool>&visited, int u , int &count ) {
    visited[u] = true ; 
    count++ ; 
    for(int &v : adj[u]) {
        if (!visited[v]) {
            dfs(adj , visited, v , count ) ; 
        }
    }
}

int main(){
    fastio ;
    int q;  cin >> q;  
    while(q-- ) {
        int n , m , lib, road ; cin >> n >> m >> lib>> road ; 
        vector<int>adj[n] ;
        int u , v; 
        for(int i = 0 ; i < m ; ++i ) {
            cin >> u >> v; u-- ; v-- ;  
            adj[u].push_back(v); 
            adj[v].push_back(u) ; 
        }
        vector<bool>visited(n) ; 
        long long cost = 0 ; int count ; 
        for(int i = 0 ;i < n ; ++i ) {
            if ( !visited[i] ) {
                count= 0 ; 
                dfs(adj , visited,  i , count ) ; 
                cost += (lib < road ) ? count * lib :( lib + (count-1)*road) ;
            }
        }
        cout << cost << endl;



    }
    return 0 ; 
}