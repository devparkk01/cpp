/*
https://leetcode.com/problems/remove-element/description/

*/


/*
time: O(n), use two pointer approach


*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size(); 
        if ( n == 0) return 0; 

        int i = 0 , j =0 ;
        while(j < n) {
            if( nums[j] != val) {
                swap(nums[i], nums[j]);
                i++; j++;
            } else{
                j++; 
            }
        }
        return i;
    }
};