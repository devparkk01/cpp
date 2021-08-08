/*
https://leetcode.com/problems/combination-sum-ii/

find unique combination :
contains duplicates ,and any number can be used only once

*/

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
			if (i > start && candidates[i] == candidates[i - 1 ]) continue ;
			subset.push_back(candidates[i]) ;
			find(candidates , target - candidates[i] , i + 1 , subset , ans ) ;
			subset.pop_back() ;
		}


	}

};

