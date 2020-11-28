/*You are given an integer array nums sorted in ascending order, and an integer target.
Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7]
might become [4,5,6,7,0,1,2]).
If target is found in the array return its index, otherwise, return -1.
*/

#include<vector>
#include<iostream>
using namespace std;

int search(vector<int>& nums, int target) {
    int smallIndex = 0 ;
    int n = nums.size() ;
    int low = 0 ; int high = n - 1 ;
    int mid ;

    if ( n == 1 || nums[0] < nums[n - 1]) smallIndex = 0 ;

    else {
        while (low <= high ) {
            mid = low + (high - low ) / 2 ;
            if (nums[mid] > nums[mid + 1 ]) {
                smallIndex = mid + 1 ;
                break ;
            }
            else if ( nums[mid] < nums[mid - 1 ]) {
                smallIndex = mid ;
                break ;
            }
            else if (nums[mid] > nums[0])
                low = mid + 1 ;
            else if ( nums[mid] < nums[0])
                high = mid - 1 ;
        }
    }
    high = n - 1 ;
    if ( target <= nums[high]) {
        low = smallIndex ;
    }
    else {
        low = 0 ; high = smallIndex - 1 ;
    }
    while (low <= high ) {
        mid = low + (high - low ) / 2 ;
        if (nums[mid] == target ) return mid ;
        else if (target < nums[mid]) high = mid - 1 ;
        else if ( target > nums[mid]) low = mid + 1 ;
    }
    return -1 ;

}

signed main () {
    vector<int>nums = {4, 5, 6 , 7 , 0 , 1 , 2 } ;
    int target = 5 ;
    cout << search(nums , target) << endl;

    return 0 ;
}