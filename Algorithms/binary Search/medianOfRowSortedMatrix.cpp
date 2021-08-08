
/*
https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#

time : O(32 * r * log(c))


*/

class Solution {
public:
	int median(vector<vector<int>> &matrix, int r, int c) {
		// code here
		int low = matrix[0][0] ;
		int high = matrix[0][0] ;
		for (int i = 0 ; i < r ; ++i) {
			for (int j = 0; j < c ; ++j) {
				low = min(low , matrix[i][j]) ;
				high = max(high , matrix[i][j]) ;
			}
		}
		int desired = (r * c ) / 2 ;
		int mid ; int count ;
		while (low <= high) {
			int mid = low + (high - low ) / 2 ;
			count = NumberLessThanEqual(matrix , r , c , mid ) ;
			if (count <= desired) {
				low = mid + 1 ;
			}
			else high = mid - 1  ;

		}
		return low ;

	}
	int NumberLessThanEqual(vector<vector<int>>&matrix , int r , int c , int num) {
		int ans = 0 ;
		for (int i = 0 ; i < r ; ++i) {
			ans += (upperbound(matrix[i] , num )) ;
		}
		return ans ;
	}
	int upperbound(vector<int>&a , int num) {
		int ans = 0 ;
		int low = 0 , high = a.size() - 1  ;
		while (low <= high ) {
			int mid = low + (high -  low) / 2 ;
			if (a[mid] > num) {
				high = mid - 1 ;
			}
			else low = mid + 1 ;
		}
		return low ;

	}



};