/*
https://leetcode.com/problems/combination-sum/

find unique combination :
no duplicates , an element can be selected any no of times

*/

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin() , candidates.end() )  ;
		vector<vector<int>>ans ;
		vector<int>subset ;

		find(candidates , target , 0 , subset, ans ) ;

		return ans ;
	}

	void find(vector<int>&candidates , int target , int start , vector<int>&subset , vector<vector<int>>&ans ) {

		if (target == 0) {
			ans.push_back(subset ) ;
			return ;
		}
		if (start == candidates.size() ) return ;


		for (int i = start ; i < candidates.size() ; ++i) {
			if (candidates[i] > target ) continue ;
			subset.push_back(candidates[i]) ;
			find(candidates , target - candidates[i] , i  , subset , ans ) ;
			subset.pop_back() ;
		}


	}

};