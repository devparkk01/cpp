/*Given a Binary Tree. Check whether it is Symmetric or not, i.e. whether the binary tree is
 a Mirror image of itself or not.
 time : O(n) , space : O(h)
*/

bool symmetric(Node *root1 , Node *root2 ) {
    if ( !root1 && !root2 ) return true ; 
    if ( !root1 || !root2 ) return false ; 
    if (root1->data == root2->data ) {
        bool left = symmetric(root1->left , root2->right ) ;//very important 
        bool right = symmetric(root1->right , root2->left ) ;// very important 
        return left && right ; 
    }
    return false ; 
}

bool isSymmetric(Node* root)
{
	if (root == NULL ) return true;
	else 
	    return symmetric(root->left , root->right ) ;
}