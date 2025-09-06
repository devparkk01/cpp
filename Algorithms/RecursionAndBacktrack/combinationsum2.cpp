/*
https://leetcode.com/problems/combination-sum-ii/

find unique combination :
contains duplicates ,and any number can be used only once

*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end() ); 
        vector<vector<int>> ans; 
        vector<int>cur; 
        util(candidates, cur, ans, target, candidates.size() -1 );
        return ans; 
    }

    void util(vector<int>&candidates, vector<int>&cur, vector<vector<int>>&ans, int target, int last){
        if (target == 0 ) {
            ans.push_back(cur);
            return ; 
        }
        if ( last < 0 ) {
            return ; 
        }

        // include 
        if (target >= candidates[last] ) {
            cur.push_back(candidates[last]);
            util(candidates, cur, ans, target - candidates[last], last - 1);
            cur.pop_back();
        }

        // exclude 
        // remove duplicates
        while(last > 0 && candidates[last] == candidates[last - 1]) {
            last--; // keep moving towards left 
        }

        util(candidates, cur, ans, target, last - 1);

    }
};