#include<iostream>
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL)  ; 

using namespace std ; 

string solve(int *arr , int n ) {
	int pref[n+2] ; pref[0] = 0 ; 
	int suf[n+2] ; suf[n+1] = 1e9 ; 

	for (int i = 1 ;i <= n ; ++i ) {
		pref[i]= max(pref[i-1] , arr[i]) ;
	}
	for (int i = n ; i>= 1 ; --i ) {
		suf[i] = min(suf[i+1] , arr[i]) ; 
	}
	int c = 0  ; 
	for (int i = 1 ;i <=n-1 ; ++i ) {
		if ( pref[i] < suf[i+1]) c++ ; 
	}
	if (c%2 == 0 ) return "Ashish" ;
	else return "Jeel" ; 
}

int main () {
	fastio ; 
	int t ; cin >>t ;
	while (t-- ) {
		int n ; cin >> n; 
		int arr[n + 2 ] ;
		for (int i = 1 ;i <= n ; ++i  ) cin >> arr[i] ;

		cout << solve(arr , n ) << endl; 
	}

	return 0 ; 
}