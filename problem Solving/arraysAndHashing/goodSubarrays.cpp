/*
https://leetcode.com/problems/subarrays-with-k-different-integers/

sliding window method
*/


class Solution {
public:
	int subarraysWithKDistinct(vector<int>& nums, int k) {
		return count(nums , k) - count(nums , k - 1 );
	}

	int count(vector<int>&nums , int k) {
		int ans = 0 ;
		unordered_map<int , int> hash ;
		int l = 0 ;

		for (int r = 0 ; r < nums.size() ; ++r) {
			hash[nums[r]]++ ;

			if (hash.size() <= k ) {
				ans += (r - l + 1 ) ;
			}
			else if (hash.size() > k ) {
				while (hash.size() > k ) {
					hash[nums[l]]--  ;
					if (hash[nums[l]] == 0 ) hash.erase(nums[l]) ;
					l++ ;
				}
				ans += (r - l + 1 ) ;
			}
		}
		return ans ;
	}
};