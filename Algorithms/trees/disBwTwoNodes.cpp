/*Given a binary tree and two node values your task is to find the minimum distance between them.

 time :O(n) , space : O(h)

*/


Node *findLca (Node *root , int a , int b ) {
    if (!root ) return NULL ; 
    if( root->data == a || root->data == b ) return root ; 
    Node*left = findLca(root->left , a , b ) ;
    Node *right = findLca(root->right , a, b ) ;
    if (left && right ) return root ; 
    if (left ) return left ;
    if (right ) return right ;
    return NULL ; 
}

int dis (Node *root , int a , int count) {
    if (root == NULL ) return 0 ; 
    if (root->data == a ) return count ; 
    int left = dis(root->left , a , count +1  ) ;
    int right = dis(root->right , a , count + 1 );
    if (left ) return left ; 
    if (right ) return right ; 
    return 0 ; 
    
}
   
   
int findDist(Node* root, int a, int b) {
    Node * lca = findLca(root, a, b ) ; 
    // if (lca == NULL) return 0 ; 
    int count = 0  ;
    int dis1 = dis ( lca , a , count ) ; 
    int dis2 = dis(lca , b, count  ) ;
    return dis1 + dis2 ; 
}