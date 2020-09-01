/* Given 2 Arrays of Inorder and preorder traversal. Construct a binary tree from these 

time : O(n*n) , space : O(n)
*/



Node *buildTreeUtil(int in[], int pre[] ,int &curr , int inS ,int inE ) {
    if (inS > inE ) return NULL ; 
    Node* root = new Node(pre[curr]) ; // construct the node 
    int mid ;
    // find curr element's index in inorder traversal 
    for(int i = inS ;i<=inE ; ++i ) {
        if(in[i] == pre[curr]) {
            mid = i ; break ; 
        }
    }
    curr++ ;// increment curr 
    root->left = buildTreeUtil(in ,pre , curr , inS , mid-1 ) ; 
    root->right = buildTreeUtil(in , pre , curr , mid+1 , inE) ; 
    return root ; 
}

Node* buildTree(int in[],int pre[], int n)
{
    int curr = 0  ; 
    return buildTreeUtil(in ,pre  , curr ,0 ,  n-1 ) ;
    
}