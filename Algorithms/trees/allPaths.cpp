/*Given a Binary Tree of size N, you need to find all the possible paths from root node
 to all the leaf node's of the binary tree.
time : O(n) ,space : O(h), output space is not considered . 

*/

// sending the reference of path as well as curPath 
void pathsUtil (Node *root , vector<vector<int>> &path , vector<int> &curPath ) {
    if (root != NULL ) {
        curPath.push_back(root->data) ; 
        if( root->left == NULL && root->right == NULL ) {
            path.push_back(curPath ) ; 
        }
        pathsUtil (root->left , path , curPath) ; 
        pathsUtil (root->right , path ,curPath ) ;
        curPath.pop_back() ; 
    }
}

vector<vector<int>> Paths(Node* root)
{
    vector<vector<int>> path  ; 
    vector<int> curPath ; 
    pathsUtil(root , path , curPath  ) ; 
    return path ; 
}