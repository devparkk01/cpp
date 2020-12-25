/* https://codeforces.com/problemset/problem/107/A

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