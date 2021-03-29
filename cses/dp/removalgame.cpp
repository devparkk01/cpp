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

ll mem[5001][5001] ;


ll solve(int a[] , int start , int end ) {
	if ( start == end ) return a[start ] ;
	if ( start + 1 == end ) return max(a[start] , a[end]) ;
	if ( mem[start][end] != -1 ) return mem[start][end] ;

	ll x = a[start] + min(solve(a , start + 2 , end) , solve(a , start + 1 , end - 1 ));
	ll y = a[end] + min(solve(a , start + 1 , end - 1) , solve(a , start , end - 2)) ;

	mem[start][end] = max(x , y ) ;
	return mem[start][end ] ;

}

signed main () {
#ifndef ONLINE_JUDGE
	freopen("input1.txt" , "r" , stdin) ;
	freopen("output1.txt" , "w" , stdout) ;
#endif

	fastio  ;
	int n ; cin >> n ; int a[n] ;
	f(i , 0 , n) cin >> a[i] ;
	memset(mem , -1 , sizeof(mem)) ;

	cout << solve(a , 0 , n - 1  ) ;

	return 0 ;

}