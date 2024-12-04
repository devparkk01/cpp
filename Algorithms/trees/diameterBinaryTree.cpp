/*Given a Binary Tree, find diameter of it.
The diameter of a tree (sometimes also called the width ) is the number of nodes on the longest 
path between two end nodes . 

time : O(n) , space : O(h) , h  = height of the tree . 

*/


// returns height of the tree . in this function we are passing dia by reference . 
int height (Node *root , int &dia ) {
    if (root == NULL ) return 0 ; 
    int left = height (root->left ,dia ) ;
    int right = height (root->right , dia ) ;
    if ( left + right + 1 > dia ) // update dia
        dia = left + right + 1 ; 
    
    return max( left , right ) + 1 ; // returning height
}

int diameter(Node* root ) {
    int dia = 0 ; 
    height (root , dia ) ; 
    return dia ; 
}