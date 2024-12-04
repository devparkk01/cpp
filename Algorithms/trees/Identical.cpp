/*Given two binary trees, the task is to find if both of them are identical or not.

time : O(n) , space : O(h )
*/



bool isIdentical (Node *root1 , Node *root2 ) {
	if (!root1 && !root2) return true;
	if ( !root1 || !root2 ) return false ;
	if (root1->data == root2->data ) {
		bool left = isIdentical(root1->left , root2->left ) ;
		bool right = isIdentical(root1->right , root2->right ) ;
		return left && right ;
	}
	return false ;
}