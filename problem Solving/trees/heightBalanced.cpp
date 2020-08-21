/*Given a binary tree, find if it is height balanced or not. 
A tree is height balanced if difference between heights of left and right 
subtrees is not more than one for all nodes of tree.

time : O(n ) , space : O(h) , h = height of the tree 
*/

int height (Node *root , bool &isBal) {
    if (root == NULL ) return 0 ; 
    int left = height(root->left , isBal);
    int right = height(root->right , isBal) ; 
    if (abs(left -right ) > 1 ) isBal = false ; // set isBal to false 
    
    return (left > right ) ? left +1 : right+ 1 ; 
}

bool isBalanced(Node *root )
{
    bool isBal = true ; //initially isBal to true 
    height(root , isBal) ; // passing isBal by reference 
    return isBal ; 
}
