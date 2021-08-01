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



int maxPathSum(Node* root) {
  // code here
  int msum = INT_MIN  ;
  int x = sum(root, msum ) ;
  if (msum == INT_MIN) return x ;
  return msum ;
}
int sum (Node *root , int &msum) {
  if (!root) return INT_MIN ;
  if (!root->left && !root->right ) return root->data ;
  int left = sum(root->left , msum) ;
  int right = sum(root->right , msum) ;
  if (root->right && root->left ) {
    msum = max(msum , left + right + root->data ) ;
  }
  return max(left , right ) + root->data ;


}