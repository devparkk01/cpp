/*

https://practice.geeksforgeeks.org/problems/combination-sum-1587115620/1#

find unique combination :
contains duplicates , an element can be selected any no of times
*/

class Solution {
public:

	vector<vector<int> > combinationSum(vector<int> &A, int B) {
		sort(A.begin() , A.end() ) ;
		vector<vector<int>> ans ;
		vector<int>subset ;
		find(A , B , 0 , subset , ans ) ;

		return ans ;


	}

	void find(vector<int>&A , int sum , int start, vector<int>&subset, vector<vector<int>>&ans ) {
		if (sum == 0 ) {
			ans.push_back(subset ) ;
			return ;
		}
		if (start == A.size() ) return ;


		for (int i = start ; i < A.size() ; ++i) {
			if (A[i] > sum ) continue ;
			else {
				if (i > start && A[i] == A[i - 1 ]) continue ;
				subset.push_back(A[i]) ;
				find(A , sum - A[i] , i , subset , ans ) ;
				subset.pop_back() ;
			}
		}


	}
};


