/*
https://leetcode.com/problems/path-sum-iii/


think of prefix sum approach . Very good question . DO try it again
*/


class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		unordered_map<int , int >counts ;
		int ans = 0 ;
		util(root , 0 , counts , sum , ans ) ;
		return ans ;
	}
	void util(TreeNode *root, int cursum, unordered_map<int , int >&counts , int &sum , int &ans) {
		if (root == NULL) return ;
		cursum += root->val ;
		if (cursum == sum) ans++ ;
		ans += counts[cursum - sum] ;
		counts[cursum]++ ;

		util(root->left  , cursum , counts , sum , ans ) ;
		util(root->right  , cursum , counts , sum , ans ) ;

		counts[cursum]--  ;

	}
};