/*Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in order.
*/

/*
logic : do normal binaary search . If the target exists then return its inddex . If target
doesn't exist then ,at the end ,low  will be pointing to the next higher position .
low will be our answer
*/

#include<iostream>
#include<vector>
using namespace std ;

int searchInsertPosition(vector<int> &nums , int target ) {
	int n = nums.size() ;
	int low = 0 , high = n - 1 ;
	int mid  ;
	while ( low <= high ) {
		mid = low + (high - low ) / 2 ;
		if ( nums[mid] == target) return mid ;
		else if ( nums[mid] < target )
			low = mid + 1 ;
		else if ( nums[mid] > target ) {
			high = mid - 1 ;
		}
	}
	return low ;

}

signed main() {
	vector<int> nums = { 2 , 3 ,  5 , 11 } ;
	int target = 8 ;
	cout << searchInsertPosition(nums , target ) << endl;
	target = 15  ;
	cout << searchInsertPosition(nums , target) << endl;
	target = 5 ;
	cout << searchInsertPosition(nums , target ) << endl;

	return 0 ;
}