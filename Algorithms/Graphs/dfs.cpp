#include<bits/stdc++.h>
using namespace std ;

// time complexity 0(V+E) , space complexity 0(V)

void dfsUtil (vector<int> g[] , vector<bool> &seen , vector<int>&trav, int v) {
    seen[v] = 1 ;
    trav.push_back(v) ;
    for (int x : g[v] ) {
        if ( !seen[x]) {
            dfsUtil(g , seen, trav , x ) ;
        }
    }
}


vector <int> dfs(vector<int> g[], int N , int start )
{
    vector<int> trav ; trav.reserve(N) ;
    vector<bool>seen(N) ;
    dfsUtil(g , seen , trav , start) ;
    return trav ;
}