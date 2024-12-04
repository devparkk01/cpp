/*
https://leetcode.com/problems/count-number-of-nice-subarrays/description/
*/


/*Think how this problem can be changed to counting the total no of subarrays having sum k.

Time: O(n)
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0; 
        unordered_map<int , int > cnt; 
        int prefixSum = 0 ; 

        cnt[0] = 1; 
        for( int i = 0 ; i < n ; ++i) {
            prefixSum += (nums[i] % 2) ? 1 : 0; 
            if ( cnt.find(prefixSum - k ) != cnt.end()) {
                ans += cnt[prefixSum -k ]; 
            }        
            cnt[prefixSum]++ ;     
        }
        return ans; 

    }

};