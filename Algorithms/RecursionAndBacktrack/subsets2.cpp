/*
https://leetcode.com/problems/subsets-ii/


Time Complexity: O(n(2 ^ n))
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int>curSubset;
        vector<vector<int>>allSubsets; 
        allSubsets.push_back(curSubset);

        util(nums, curSubset, allSubsets, 0);

        return allSubsets; 
    }

    void util(vector<int>&nums, vector<int>&curSubset, vector<vector<int>>&allSubsets, int start) {

        if (start == nums.size() ) return ;
        // include current element 
        curSubset.push_back(nums[start]);
        allSubsets.push_back(curSubset);
        util(nums, curSubset, allSubsets, start + 1);

        // exclude current element  
        curSubset.pop_back(); 
        // remove duplicates from right side 
        while( start < nums.size() -1  && nums[start] == nums[start + 1]) {
            start++; 
        }
        util(nums, curSubset, allSubsets, start +1);
    }
};