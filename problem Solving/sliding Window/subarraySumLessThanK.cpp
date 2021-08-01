/*
https://www.interviewbit.com/problems/counting-subarrays/#

Given an array A of N non-negative numbers and you are also given non-negative number B.
You need to find the number of subarrays in A having sum less than B. We may assume that there
 is no overflow.

Problem Constraints
1 <= N <= 104
1 <= A[i] <= 100
1 <= B <= 108
*/


int Solution::solve(vector<int> &A, int B) {
	int n =  A.size() ;
	int l = 0 ;
	int sum = 0 ;
	int count = 0 ;
	for (int r = 0 ; r < n ; ++r) {
		sum += A[r] ;
		while (sum >= B && l < r ) {
			sum -= A[l] ;
			l++ ;
		}
		if (sum < B) {
			count += (r - l + 1) ;
		}
	}
	return count ;
}
