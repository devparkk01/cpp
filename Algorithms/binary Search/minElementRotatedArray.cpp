/*Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand. 
i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
Return the minimum element of this array.
*/

#include<iostream>
#include<vector>
using namespace std ; 

int findMin(vector<int>& nums) {
    int n = nums.size() ; 
    if ( n== 1 ) return nums[0] ; // no need to check 
    else if (nums[0] < nums[n -1 ])  return nums[0] ;  	// array is already sorted 

    int low = 0 , high = nums.size() -1 ; 
    int mid ; 
    // proceed with normal binary search
    while ( low <= high ) {
        mid = low + (high - low ) / 2 ; 
        if( nums[mid] > nums[mid + 1 ]) return nums[mid + 1] ; 
        else if (nums[mid] < nums[mid -1] ) return nums[mid] ; 
        else if ( nums[mid] > nums[0])
            low = mid + 1 ; 
        else if ( nums[mid] < nums[0])
            high = mid - 1 ; 
    }
    return -1 ; // just for returnsake 
    
}

signed main() {
	vector<int>nums = { 3 , 5 ,  1 , 2 } ;
	cout << findMin(nums) << endl ;

	return 0 ; 
}