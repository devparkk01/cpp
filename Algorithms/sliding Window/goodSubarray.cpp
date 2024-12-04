
/*  https://leetcode.com/problems/continuous-subarray-sum/description/

*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size() ; 

        unordered_map<int , int > hashmap; 
        hashmap[0] = -1; 
        int sum = 0 ; 

        for( int i = 0 ; i < n ; ++i) {
            sum += nums[i];

            if (hashmap.find(sum%k) != hashmap.end()) {
                if ( i - hashmap[sum % k]  >= 2) {
                    return true; 
                }
            } else {
                hashmap[sum % k ] = i ;
            }
        }
        return false; 

    }
};