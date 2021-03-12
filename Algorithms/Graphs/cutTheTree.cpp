#include<bits/stdc++.h>
using namespace std ;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define endl '\n'
#define ll long long
#define f(i , k , n ) for(int i = k ; i < n ; ++i)
#define ip pair<int , int >
#define um unordered_map<int , int >
#define us unordered_set<int >
#define pb push_back
#define vec vectorx

int dfs(vec<int>adj[] , vec<int>&a  , int u , int v  ) {
    int sum = a[u] ;
    for (int &x : adj[u]) {
        if ( x != v ) {
            sum += dfs(adj , a , x , u ) ;
        }
    }
    return sum ;
}


signed main () {
#ifndef ONLINE_JUDGE
    freopen("input1.txt" , "r" , stdin) ;
    freopen("output1.txt" , "w" , stdout) ;
#endif
    fastio  ;
    int n ; cin >> n;  vec<int>a(n ) ;
    f(i , 0 , n ) cin >> a[i] ;
    vec<ip>edgeList(n ) ;
    vec<int>adj[n] ;
    int u , v ;
    f(i , 0 , n - 1  ) {
        cin >> u >> v ; u-- ; v-- ;
        edgeList[i] = {u , v  } ;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // vec<bool>visited(n) ;
    int ans = 1e9 ; int sum1 , sum2 ;
    int curans = 0 ;
    f(i , 0 , n - 1 ) {
        u = edgeList[i].first ;
        v = edgeList[i].second ;
        sum1 = dfs(adj , a,  u , v  ) ;
        sum2 = dfs(adj , a ,  v , u  ) ;
        curans = abs(sum1 - sum2 ) ;
        ans = min(ans , curans )  ;
    }
    cout << ans << endl;

    return 0 ;

}
