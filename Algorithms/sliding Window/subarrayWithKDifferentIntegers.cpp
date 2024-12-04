/*
https://leetcode.com/problems/subarrays-with-k-different-integers/

sliding window method
*/


class Solution {
public:

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countAtMost(nums, k) - countAtMost(nums, k - 1);
    }

	    int countAtMost(vector<int>&nums, int k ) {
        int n =  nums.size(); 
        int count = 0 ; 

        unordered_map<int, int > hashmap; 
        int l = 0 ;
        for(int r = 0 ; r < n ; ++r) {
            hashmap[nums[r]]++;
            // keep shrinking the left window until the window size becomes k 
            while( hashmap.size() > k) {
                hashmap[nums[l]]--;
                if( hashmap[nums[l]] == 0) {
                    hashmap.erase(nums[l]);
                }
                l++; 
            }
            count += (r-l+1);
        }
        return count; 

    }
};