/*Given a binary tree and an integer S,check whether there is root to leaf path with its sum as S.

time :O(n) ,space : O(h)
*/

void sumUtil ( Node * root , int sum , int curSum, bool&isFound ) {
    if (root == NULL ) return; 
    if (isFound == false ) {
        curSum+= root->data ; 
        if ( !root->left &&  !root->right  && curSum == sum )
            isFound = true ; 
        sumUtil(root->left ,sum , curSum , isFound ) ; 
        sumUtil (root->right , sum , curSum , isFound ) ; 
    }
}


bool hasPathSum(Node *root, int sum) {
    bool isFound = false ; 
    int curSum = 0 ; 
    sumUtil (root , sum , curSum , isFound) ; 
    return isFound ; 
}


// finding all paths with given sum 
// time : O(n)

void pathSumUtil(Node *root,int sum ,int curSum, vector<vector<int>>&path,vector<int> &curPath ) {
    if (root == NULL ) return ; 
    curSum += root->data ; 
    curPath.push_back(root->data ) ; 
    if (root->left == NULL && root->right == NULL && curSum == sum ) {
        path.push_back(curPath) ; 
    }
    pathSumUtil(root->left , sum , curSum , path , curPath) ; 
    pathSumUtil(root->right , sum , curSum  , path , curPath ) ;
    curPath.pop_back() ;
}


vector<vector<int>> pathSum (Node *root , int sum ) {
    vector<vector<int> > path ; 
    vector<int> curPath ;
    int curSum = 0 ; 
    pathSumUtil(root,sum , curSum , path , curPath) ; 
    return path ; 
}