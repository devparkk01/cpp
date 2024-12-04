/*Given a binary tree , a node and a positive integer K., your task is to complete the function 
kthAncestor(), the function should return the Kth ancestor of the given node in the binary tree. 
If there does not exist any such ancestor then return -1.

time : O(n) , space : O(h)
*/


// searching the node
bool KthAncestorUtil(Node *root, int k , int node,int &count, int &anc ) {
    if (root == NULL ) return false; 
    if (root->data == node ) return true; // found the node 
    // search in the left subtree
    bool left = KthAncestorUtil(root->left , k , node ,count , anc ) ;
    // search in the right subtree
    bool right = KthAncestorUtil(root->right , k , node ,count , anc ) ; 
    if (left || right ) {
        count++ ; 
        if (count == k ) anc = root->data; 
    }
    return left || right ; 
    
}


int kthAncestor(Node *root, int k, int node)
{
    int anc = INT_MIN ; int count = 0 ; 
    KthAncestorUtil(root , k , node ,count ,  anc) ; 
    if ( anc == INT_MIN ) return -1 ; 
    else return anc ; 
    
}