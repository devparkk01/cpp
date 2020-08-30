/*Given a binary tree in which each node element contains a number. Find the maximum possible 
sum from one leaf node to another.
           -15                               
         /     \                          
        5        6                      
      /  \      / \
    -8    1    3   9
   /  \              \
  2   -3              0
                     / \
                    4  -1
                       /
                     10  

Output :  27
The maximum possible sum from one leaf node 
to another is (3 + 6 + 9 + 0 + -1 + 10 = 27)

*/
/*
At any node , we care about only two sums , 
1-> max sum from this current node to a leaf (whether in left subtree or right subtree)
2-> max sum between two leaves . 

time : O(n) , space : O(h) , recursive space . 
*/

int maxPathSumUtil (Node *root ,int &maxSum ) {
    if (root == NULL )  return 0 ; 
    // leaf node
    if ( root->left == NULL && root->right == NULL  ) return root->data ; 
    // max root to leaf path sum in left subtree 
    int left = maxPathSumUtil(root->left , maxSum ) ; 
    // max root to leaf path sum in right subtree
    int right = maxPathSumUtil(root->right , maxSum ) ; 

    if ( root->left != NULL && root->right != NULL ) { // full node
        maxSum = max(maxSum , left+ right + root->data ) ; 
        return max(left ,right ) + root->data  ; 
    }
    if( root->left == NULL) {// no left child 
        return right + root->data ; 
    }
    if(root->right == NULL ) {// no right child 
        return left + root->data ; 
    }
    
}

int maxPathSum(Node* root)
{ 
    int maxSum = INT_MIN ;
    maxPathSumUtil(root , maxSum ) ; 
    return maxSum ; 
    
}
