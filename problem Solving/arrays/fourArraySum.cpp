/*Given an array of integers and a target number . Find all the unique quadruplets from the
given array that sums up to the given target  .
There must not be any duplicate quadruplets , and quadrupltes must be internally sorted .

*/

#include<bits/stdc++.h>
using namespace std ;
#define vec vector
#define endl '\n'

/* time : O(n * n * n)  , space : O(n * n ) */

vector<vector<int>> uniqueQuadruplet(vector<int> &arr, int target ) {
	int n = arr.size() ;
	vec<vec<int>>res ;
	if ( n < 3 ) return res ;
	sort(arr.begin() , arr.end() ) ;
	int a, b , c , d  ;
	for (int i = 0 ; i < n - 3 ; ++i ) {
		if (i != 0 && arr[i] == arr[i - 1]) continue ;
		a = arr[i] ;
		for (int j = i + 1 ; j < n - 2 ; ++j ) {
			if ( j != i + 1 && arr[j] == arr[j - 1 ]) continue ;
			b = arr[j] ;
			int k = j + 1 , l = n - 1 ;
			while (k < l ) {
				c = arr[k] , d = arr[l] ;
				if ( a + b + c + d == target ) {
					res.push_back({a , b , c , d }) ;
					// removing duplicates from left end
					while (k < l and arr[k] == arr[k + 1 ]) k++ ;
					// removing duplicates from right end
					while (k < l and arr[l] == arr[l - 1 ]) l-- ;
					k++ ; l-- ;
				}
				else if ( a + b + c + d < target ) k++ ;
				else l-- ;
			}
		}
	}

	return res ;

}

void print ( vector<vector<int>>&v ) {
	for (int i = 0 ; i < v.size() ; ++i ) {
		for (int j = 0 ; j < v[i].size() ; ++j ) {
			cout << v[i][j] << " " ;
		}
		cout << endl;
	}
}


signed main () {
	vec<int>arr = { 2, 7, 4, 0, 0 , 2, 9, 9, 5, 1, 3 };
	int target = 20;
	vec<vec<int>>res = uniqueQuadruplet(arr , target)  ;
	print(res) ;

	return 0  ;
}