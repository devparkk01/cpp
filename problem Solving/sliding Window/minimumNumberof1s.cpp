/*
https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1#


time : O(n) , space : O(1)

sliding window method
 */



int findZeroes(int arr[], int n, int m) {
	// code here
	int l = 0 ;
	int ans = 0 ; int count = 0 ; // count of zeros in the current window

	for (int r = 0 ; r < n ; ++r) {
		if (arr[r] == 0 ) count++ ;
		if (count <= m) {
			ans = max(ans , r - l + 1 ) ;
		}
		else if (count > m ) {
			while (l < r && count > m) {
				if (arr[l] == 0 )  count-- ;
				l++ ;
			}
			ans = max(ans , r - l + 1 ) ;
		}
	}

	return ans ;
}