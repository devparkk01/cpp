/*
https://leetcode.com/problems/subsets-ii/


Time Complexity: O(n(2 ^ n))
*/


class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int n = nums.size() ;
		sort(nums.begin() , nums.end() ) ; // sorting is must

		vector<vector<int>>res ;
		vector<int>cur ;
		res.push_back(cur ) ;
		findsubsets(nums , 0 , cur , res ) ;

		return res ;
	}


	void findsubsets(vector<int>&nums , int start , vector<int>&cur , vector<vector<int>>&res) {
		if (start == nums.size() ) {
			return ;
		}
		for (int i = start ; i < nums.size() ; ++i) {
			if (i > start && nums[i] == nums[i - 1]) continue ;
			cur.push_back(nums[i]) ;
			res.push_back(cur) ;
			findsubsets(nums , i + 1 , cur , res ) ;
			cur.pop_back() ;
		}

	}
};