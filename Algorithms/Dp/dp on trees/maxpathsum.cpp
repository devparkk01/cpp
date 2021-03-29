/*  https://leetcode.com/problems/binary-tree-maximum-path-sum/
*/


int util(TreeNode*node , int &ans ) {
	if ( node == NULL ) return 0 ;
	int l = util(node->left , ans ) ;
	int r = util(node->right , ans ) ;

	int temp = max({node->val , l + node->val , r  + node->val }) ;
	ans = max({ans , temp , l + r + node->val }) ;
	return temp ;

}

int maxPathSum(TreeNode* root) {
	int ans = root->val ;
	util(root , ans ) ;
	return ans ;

}