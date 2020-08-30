/*Given a Binary Tree and a target key, you need to find all the ancestors
 of the given target key.

time : O(n) , space : O(h)
*/

// searching the target 
bool AncestorsUtil(Node *root , int target , vector<int> &v) {
    if (root == NULL ) return false ;
    if (root->data == target ) return true ; // found the target 
    // search in the left subtree 
    bool left = AncestorsUtil(root->left , target  , v ) ;
    // search in the right subtree
    bool right = AncestorsUtil(root->right , target  , v ) ;
    
    if(left || right ) {
        v.push_back(root->data) ; 
    }
    return left || right ; 
    
}


vector<int> Ancestors(struct Node *root, int target)
{
    vector<int> v ; 
    AncestorsUtil(root , target  , v ) ; 
    return v ;
}