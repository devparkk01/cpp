/* https://codeforces.com/problemset/problem/107/A

first , try to understand the question properly .
after that I learnt that , I need to find out total no of connected components in this
given graph . total no of tanks I need to install will be equal to the total no of
connected components . Then i will run dfs on each of these connected components . but it's not
as easy as it looks . from which node(house) should I actually run dfs in any connected component.
of course , I need to start from that node(house ) in which I'm going to install a tank .



time : O(n) , space : O(n)
*/

#include<bits/stdc++.h>
using namespace std;
#define vec vector
#define ip pair<int , int >
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false ) ; cin.tie(NULL) ;

void dfs(int i , vec<int>&triplet , int &maxi , vec<int>&start , vec<int>&dia) {
    maxi = min(maxi , dia[i]) ;
    int j = start[i] ;
    if ( start[j] != 0) dfs(j , triplet , maxi , start , dia ) ;
    else {
        triplet[1] = j ; triplet[2] = maxi ;
    }

}

int main() {
    fastio ;
    int n , p ; cin >> n >> p ;
    vec<int>start(n + 1 ) ; vec<int>end(n + 1 ) ; vec<int>dia(n + 1 ) ;
    int a , b , d ;
    for (int i = 0 ; i < p; ++i ) {
        cin >> a >> b >> d ;
        start[a] = b ; end[b] = a ;
        dia[a] = d ;
    }
    int count = 0 ;
    vec<vec<int>>ans ;
    for (int i = 1 ; i <= n; ++i ) {
        if ( start[i] != 0 && end[i] == 0) {
            count++ ;
            vec<int>triplet(3) ;
            triplet[0] = i ;
            int maxi = 10000000;
            dfs(i , triplet , maxi , start , dia  ) ;
            ans.push_back(triplet) ;
        }
    }
    cout << count << endl;
    for (int i = 0 ; i < count ; ++i ) {
        cout << ans[i][0] << " " <<  ans[i][1] << " " << ans[i][2] << endl ;
    }


    return 0;
}



// second solution


#include<bits/stdc++.h>
using namespace std ;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define endl '\n'
#define ll long long
#define f(i , k , n ) for(int i = k ; i < n ; ++i)
#define ip pair<int , int >
#define um unordered_map<int , int >
#define us unordered_set<int >
#define vec vector
#define pb push_back

struct connection {
    int to , diameter , direction ;
} ;


struct triplet {
    int tank , pipe , mindiameter ;
};


void dfs(int i , vec<connection>adj[] , triplet &temp , int curdia ,  vec<bool>&visited ) {
    visited[i] = 1 ;
    temp.mindiameter = min(curdia , temp.mindiameter) ;

    if ( adj[i].size() == 1 && adj[i][0].direction == 1 ) {
        temp.pipe = i ; return ;
    }

    for (connection &x : adj[i]) {
        if (!visited[x.to]) {
            dfs(x.to , adj , temp , x.diameter , visited) ;
        }
    }

}

signed main () {
#ifndef ONLINE_JUDGE
    freopen("input1.txt" , "r" , stdin) ;
    freopen("output1.txt" , "w" , stdout) ;
#endif

    fastio  ;
    int n , p ; cin >> n >> p ;
    vec<connection>adj[n + 1] ;
    vec<bool>visited(n + 1) ;

    int a, b, d ;
    f(i , 0 , p) {
        cin >> a >> b >> d ;
        adj[a].pb({b , d , 0}) ;
        adj[b].pb({a , d , 1}) ;
    }

    vec<triplet>ans ;

    f(i , 1 , n + 1 ) {
        if (adj[i].size() == 1 && adj[i][0].direction == 0) {
            triplet temp ;
            temp.tank = i ;
            temp.mindiameter = adj[i][0].diameter ; int curdia = adj[i][0].diameter ;
            dfs(i , adj , temp , curdia ,  visited ) ;
            ans.pb(temp) ;
        }
    }
    cout << ans.size() << endl ;
    f(i , 0 , ans.size() ) {
        cout << ans[i].tank << " " << ans[i].pipe << " " << ans[i].mindiameter << endl;
    }


    return 0 ;

}