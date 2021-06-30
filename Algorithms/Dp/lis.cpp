/*The longest subsequence problem is to find a subsequence of a given sequence in which the subsequence's
elements are in sorted order , lowest to highest , and in which the subsequence is as long as possible.
The subsequene is not necessarily contiguous .

time : O(n*n) , space : O(n)
*/

#include<bits/stdc++.h>
using namespace std ;

int LIS (int arr[] , int n ) {
	if (n == 0 ) return 0 ;
	int lis[n] = {0};
	// lis[i] stores the length of the longest increasing subsequence ending at ith index

	for (int i = 0; i < n; ++i) {
		int temp = 0 ;
		//find the increasing subsequence with maximum length that ends with arr[j] where arr[j] is less
		// than the current element arr[i] , (0 <= j < i )
		for (int j = 0 ; j < i ; ++j ) {
			if (arr[j] < arr[i] )
				temp = max(temp , lis[j]) ;
		}
		lis[i] = temp + 1 ; // increase the length of longest increasing subsequence by 1
		// this is because we include ith element also .
	}
	return *max_element(lis , lis + n) ;
}


signed main () {
	int arr[] = { 24 , 18, 18 , 13 , 11, 14 , 26, 18, 1, 10, 7 , 4 , 21 , 24 , 12, 8, 29, 4 , 7 };
	int n = sizeof(arr) / sizeof(int) ;
	cout << LIS(arr , n ) ;

	return 0 ;
}