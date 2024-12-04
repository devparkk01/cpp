/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
*/


/* time: O(n)

use two pointer approach to swap the elements of the array. 


*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n  = nums.size(); 
        int i = 0, j = 0; 
        while( j < n) {
            while(j + 1 < n && nums[j] == nums[j + 1]) {
                j++;
            }
            swap(nums[i], nums[j]);
            i++; j++; 
        }
        return i; 

    }
};