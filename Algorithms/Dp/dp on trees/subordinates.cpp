/*  https://cses.fi/problemset/task/1674

*/
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

int solve(vec<vec<int>>&tree , int boss , vec<int>&subs) {
	for (int child : tree[boss]) {
		subs[boss] += (1 + solve(tree , child , subs)) ;
	}
	return subs[boss] ;
}

signed main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt" , "r" , stdin) ;
// 	freopen("output1.txt" , "w" , stdout) ;
// #endif
	fastio  ;
	int n ; cin >> n ;
	vec<vec<int>>tree( n + 1 ) ;
	int x ;
	f(i , 2 , n + 1 ) {
		cin >> x ;
		tree[x].pb(i) ;
	}

	vec<int>subs(n + 1 ) ;

	solve(tree , 1 , subs ) ;

	f(i , 1 , n + 1 ) cout << subs[i] << " " ;

	return 0 ;

}

