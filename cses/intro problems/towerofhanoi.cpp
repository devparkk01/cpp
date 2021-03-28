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

void toi(int n , int s , int d , int aux) {
	if ( n == 1 ) { cout << s << " " << d << endl ; return ; }
	toi(n - 1 , s , aux , d ) ;
	cout << s << " " << d  << endl ;
	toi(n - 1 , aux , d , s ) ;
}

signed main () {
// #ifndef ONLINE_JUDGE
// 	freopen("input1.txt" , "r" , stdin) ;
// 	freopen("output1.txt" , "w" , stdout) ;
// #endif

	fastio  ;
	int n ; cin >> n;
	int k = pow(2 , n ) - 1 ;
	cout << k << endl;

	toi(n , 1 , 3 , 2 ) ;

	return 0 ;

}

