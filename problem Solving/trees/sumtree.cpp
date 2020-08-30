/*Given a Binary Tree. Check whether it is a Sum Tree or not.
A Binary Tree is a Sum Tree in which value of each node x is equal to 
sum of nodes present in its left subtree and right subtree .


An empty tree is also a Sum Tree as sum of an empty tree can be considered to be 0. 
A leaf node is also considered as a Sum Tree.


*/

int sumUtil ( Node * root , bool &flag ) {
    if ( !root ) return 0 ;
    if ( !root->left && !root->right ) return root->data ; 
    int left = sumUtil (root->left , flag ) ;
    int right = sumUtil (root->right ,flag ) ;
    if ( left + right != root->data ) flag = false ; 
    
    return left + right + root->data ; 
}


bool isSumTree(Node* root)
{
    bool flag = true ;
    sumUtil (root , flag ) ;
    return flag ; 
}