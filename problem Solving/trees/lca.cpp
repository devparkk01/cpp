/*Given a Binary Tree with all unique values and two nodes value n1 and n2. The task is 
to find the lowest common ancestor of the given two nodes. 
We may assume that either both n1 and n2 are present in the tree or none of them is present. 

time : O(n) , space : O(h)
*/


Node* lca(Node* root ,int n1 ,int n2 )
{
    if (root == NULL ) return NULL ; 
    if( root->data == n1 || root->data == n2 ) return root ; 
    Node * left = lca (root->left , n1, n2 ) ;
    Node * right = lca(root->right , n1 , n2 ) ; 
    if (left && right ) {
       return root ; 
    }
    if (left )return left ; 
    if (right ) return right ; 
    return NULL ; 
}

