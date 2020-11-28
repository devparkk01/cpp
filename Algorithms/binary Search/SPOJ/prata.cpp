/*  https://www.spoj.com/problems/PRATA/

INput :
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1
Output:
12
36
1

*/

#include<bits/stdc++.h>
using namespace std ;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define endl '\n'
#define f(i , k , n ) for(int i = k ; i < n ; ++i )



bool isPossible(int r[] , int l , int p , int time ) {
	int count = 0 ;
	for (int i = 0 ; i < l ; ++i ) {
		count += ((-1) + sqrt(1 + 8 * time / r[i])) / 2 ;
	}
	if ( count >= p) return true ;
	else return false ;

}


int minTime(int r[] , int l , int p ) {
	int low = 0 ;
	int k = *min_element( r, r + l ) ;
	int high = (k * p * (p + 1) ) / 2 ;
	int mid , ans ;
	while (low <= high ) {
		mid = low + (high - low ) / 2 ;
		if (isPossible(r , l , p , mid )) {
			ans = mid ;
			high = mid - 1 ;
		}
		else low = mid + 1;
	}
	return ans ;

}

signed main () {
	fastio ;
	int t;  cin >> t ;
	while (t-- )  {
		int p , l ;
		cin >> p >> l ;
		int r[l] ;
		f(i , 0 , l ) cin >> r[i] ;

		cout << minTime(r , l , p ) << endl  ;
	}


	return 0 ;
}