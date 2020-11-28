/*https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/

Given an integer array arr and a target value target, return the integer value such that
when we change all the integers larger than value in the given array to be equal to value,
the sum of the array gets as close as possible (in absolute difference) to target.

In case of a tie, return the minimum such integer.

arr = [4,9,3], target = 10
Output: 3
arr = [2,3,5], target = 10
Output: 5

*/

#include<bits/stdc++.h>
using namespace std ;


int sumValue(vector<int>&arr , int value) {
	int sum = 0 ;
	for (int &x : arr) {
		if ( x > value) sum += value ;
		else sum += x ;
	}
	return sum ;
}

int findBestValue(vector<int>& arr, int target) {
	int low = 0 ;
	int high = *max_element(arr.begin() , arr.end() ) ;
	int mid , value , min_diff = target ;
	int sum ;
	while (low <= high ) {
		mid = low + (high - low ) / 2 ;
		sum = sumValue(arr , mid) ;
		if ( sum == target ) return mid ;
		if ( abs(sum - target ) < min_diff) {
			value = mid ;
			min_diff = abs(sum - target ) ;
		}
		else if ( abs(sum - target) == min_diff) value = min(mid , value) ;
		// sum - target == min_diff ;
		if ( sum > target ) high = mid - 1 ;
		else if ( sum < target ) low = mid + 1 ;
	}
	return value;
}


signed main () {
	vector<int>arr = {4 , 9 , 3 } ;
	int target = 10 ;
	cout << findBestValue(arr , target ) << endl;

	return 0 ;
}