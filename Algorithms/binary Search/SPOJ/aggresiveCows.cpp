/* https://www.spoj.com/problems/AGGRCOW/

Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls.
 The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each
other once put into a stall. To prevent the cows from hurting each other, FJ wants to
assign the cows to the stalls, such that the minimum distance between any two of them 
is as large as possible. What is the largest minimum distance?	


*/
#include<bits/stdc++.h>
using namespace std ; 
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; 
#define endl '\n'
#define f(i , k , n ) for(int i = k ; i < n ; ++i ) 


bool isPossible(int a[] , int n , int c , int minDis) {
	int lastPos = a[0] ; 
	int cows = 1 ; 
	for(int i = 1 ; i < n ; ++i ) {
		if ( a[i] - lastPos >= minDis ) {
			cows++ ;
			lastPos = a[i] ; 
			if ( cows == c ) return true ; 
		}
	}
	return false ; 

}

int minDistance(int a[] , int n , int c ) {
	sort(a , a+n ) ; 
	int low = 0 , high = a[n-1] ; 
	int mid ; int ans = 0 ; 

	while(low <= high ) {
		mid = low + (high - low ) / 2 ; 
		if (isPossible(a , n , c , mid )) {
			ans = mid ;
			low = mid + 1 ; 
		}
		else high = mid - 1; 
	}
	return ans ; 
}



signed main () {
	fastio ; 
	int  t ; cin >> t; 
	while (t-- ) {
		int n , c ; cin >> n >> c ; 
		int a[n] ; 
		f(i , 0 , n ) cin >> a[i] ;
		cout << minDistance(a , n , c ) << endl ; 
	}
	return 0 ; 
}