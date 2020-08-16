/*
Given an array A that contains N integers (may be positive, negative or zero). Find the product of the 
maximum product subarray such that after taking the mod by 1000000007, the product is maximum

*/


#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long 
using namespace std ; 

/*first technique : brute force : Time : O(n*n)

second technique : dynamic programming 
This approach is similar to kadanes algorithm for finding max sum of the subarray 
time : O(n) ,space : O(1)


*/
ll maxProdSubarray (ll A[] , int n ) {
	ll maxProd = A[0] ;
	ll curMaxProd = A[0] ;
	ll curMinProd = A[0] ;


	for(int i = 1 ; i<n ; ++i ){
		if (A[i] < 0) 
			swap(curMaxProd, curMinProd ) ;

		curMaxProd = max(curMaxProd * A[i] , A[i]) % mod ; 
		curMinProd = min(curMinProd * A[i] , A[i])% mod  ; 

		maxProd = max(maxProd , curMaxProd) ; 
	}
	return maxProd ; 
}

signed  main () {
	ll A[] = { 6, -3, -10, 0, 2 } ;
	int n = sizeof( A) / sizeof( ll ) ; 
	cout << maxProdSubarray(A, n ) << endl ; 

	return 0 ; 
}