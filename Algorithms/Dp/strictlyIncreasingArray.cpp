/*
https://practice.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1/

Given an array nums[] of N positive integers. Find the minimum number of operations required
to modify the array such that array elements are in strictly increasing order (A[i] < A[i+1]).
Changing a number to greater or lesser than original number is counted as one operation.


approach is discussed at the bottom
*/



class Solution {
public:

	int min_operations(vector<int>nums) {
		int n = nums.size() ;
		int dp[n] = {0} ;

		for (int i = 0 ; i < n ; ++i ) {
			int temp = 0 ;
			for (int j = i - 1 ; j >= 0 ; --j) {
				if (nums[j] < nums[i] && ( i - j) <= nums[i] - nums[j]) temp = max(dp[j] , temp ) ;
			}
			dp[i] = 1 + temp ;
		}
		return n - *max_element(dp , dp + n ) ;
	}
};


/*
Variation of lis
lis[i] stores the length of increasing subsequence ending at ith index ,but this is not it
there is a catch in it . Let's have a look at it
while calculating lis[i] , we will traverse all j {0 , i -1 } .
In order for arr[j] to become a part of subsequence ending at ith index , we need following
conditions :
a ) of course ( arr[i] < arr[i]) , this condition is there also in typical LIS problem
b ) difference between (arr[i] - arr[j]) must be greater than no of elements between
    these two elements , i.e , (i - j ) . This condition is very important. Otherwise we
    won't be able to create strictly increasing subsequence



*/