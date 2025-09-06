/*
https://leetcode.com/problems/combination-sum/

find unique combination :
no duplicates , an element can be selected any no of times

*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; 
        vector<int>cur; 
        util(candidates, cur, ans, target, candidates.size() -1 );
        return ans; 
    }

    void util(vector<int>&candidates, vector<int>&cur, vector<vector<int>>&ans, int target, int last){
        if (last < 0 ) return ; 
        if (target == 0 ) {
            ans.push_back(cur);
            return ;
        }
        // include 
        if (target >= candidates[last]) {
            cur.push_back(candidates[last]);
            util(candidates, cur, ans, target - candidates[last], last);
            cur.pop_back(); 
        }
        // exclude 
        util(candidates, cur, ans, target, last - 1);
    }

};