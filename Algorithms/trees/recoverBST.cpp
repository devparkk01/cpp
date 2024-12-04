/*
https://leetcode.com/problems/recover-binary-search-tree/

*/



class Solution {
public:
	void recoverTree(TreeNode* root) {
		TreeNode *prev = NULL , *first = NULL , *second = NULL;
		find(root , prev , first , second ) ;

		swap(first->val , second->val ) ;
	}
	void find(TreeNode *root , TreeNode *&prev , TreeNode *&first , TreeNode *&second ) {
		if (root == NULL) return ;

		find(root->left , prev , first , second ) ;

		if (prev == NULL) prev = root ;
		else {
			if (first == NULL && prev->val > root->val ) first = prev  ;
			if (first != NULL && prev->val > root->val ) second = root ;

			prev = root ;
		}

		find(root->right , prev , first , second ) ;
	}
};