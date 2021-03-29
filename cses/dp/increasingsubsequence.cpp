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


int findincreasingsubsequence(int a[] , int n , vec<int>&lis) {
	f(i , 1 , n ) {
		int	temp = 0 ;
		f(j , 0 , i ) {
			if ( a[j] < a[i]) {
				temp = max(temp , lis[j]) ;
			}
		}
		lis[i] = 1 + temp ;
	}

	return *max_element(lis.begin() , lis.end())  ;

}



signed main () {
#ifndef ONLINE_JUDGE
	freopen("input1.txt" , "r" , stdin) ;
	freopen("output1.txt" , "w" , stdout) ;
#endif

	fastio  ;
	int n ; cin >> n ; int a[n] ;
	f(i , 0 , n) cin >> a[i] ;
	vec<int>lis(n) ;
	lis[0] = 1 ;

	cout << findincreasingsubsequence(a , n , lis) << endl ;

	return 0 ;

}