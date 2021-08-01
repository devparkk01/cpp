/*
https://leetcode.com/problems/subsets/

*/



class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<int>cur ;
		vector<vector<int>>ans ;
		ans.push_back({}) ;

		util(nums , 0 , cur ,  ans  ) ;
		return ans ;

	}

	void util(vector<int>&nums , int start , vector<int>&cur ,  vector<vector<int>>&ans ) {

		if (start == nums.size() ) return ;
		for (int i = start ; i < nums.size() ; ++i) {
			cur.push_back(nums[i]) ;
			ans.push_back(cur) ;
			util(nums , i + 1 , cur , ans ) ;
			cur.pop_back() ;
		}


	}

};