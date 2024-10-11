/*
https://leetcode.com/problems/house-robber-ii/

*/
#include<iostream>
using namespace std; 

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 ) return nums[0];
        if (n == 2) return max(nums[0] , nums[1]);
        if( n == 3) return max({nums[0], nums[1], nums[2]});

        // House[1] to House[n-1]
        int first = robSimple(nums, 0, n -2);
        // House[2] to House[n]
        int second = robSimple(nums, 1 , n -1);

        return max(first, second);
        
    }
    // max amount we can get when we rob houses from index start to end such that no adjacent houses are robbed
    int robSimple(vector<int>&nums, int start, int end ) {
        int maxSumTillTwoHouseBack = nums[start];
        int maxSumTillOneHouseBack = max(nums[start], nums[start + 1]);

        for(int i = start + 2 ; i <= end ; ++i) {
            int curMax = max(maxSumTillTwoHouseBack + nums[i] , maxSumTillOneHouseBack );
            maxSumTillTwoHouseBack = maxSumTillOneHouseBack ; 
            maxSumTillOneHouseBack = curMax; 
        }
        return maxSumTillOneHouseBack;
    }
};