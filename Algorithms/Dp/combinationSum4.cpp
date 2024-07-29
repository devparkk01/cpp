/*
https://leetcode.com/problems/combination-sum-iv/description/

unbounded knapsack variation 

*/

#include<bits/stdc++.h>
using namespace std; 


// topdown dp approach
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // countCombinations[i] stores total no of combination to make target i 
        vector<int>countCombinations(target + 1, -1);

        
        return util(nums, target, countCombinations);

    }

    int util(vector<int>&nums, int target, vector<int>&countCombinations) {

        if (target == 0) return 1;

        if (countCombinations[target] != -1) return countCombinations[target];
        int result = 0;
        for(auto &num: nums) {
            if ( num <= target) {
                result += (util(nums, target - num, countCombinations));
            }
        }
        return countCombinations[target] = result; 
    }

};