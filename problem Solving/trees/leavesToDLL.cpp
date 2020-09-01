/*
Given a Binary Tree of size N, extract all its leaf nodes to form a Doubly Link List 
strating from the left most leaf. Modify the original tree to make the DLL thus removing 
the leaf nodes from the tree. Consider the left and right pointers of the tree to be the
 previous and next pointer of the DLL respectively.

 time : O(n) , space : O(h)
*/
//  here , we will do preorder traversal instead of inorder traversal . 


Node *convertToDLLUtil(Node *root , Node *&head , Node*&tail ) {
    if (!root ) return NULL ; 
    // processing the node
    if (!root->left && !root->right  ){
        if (head == NULL) {
            head = root ; tail = root ; 
        }
        else {
            root->left = tail ; 
            tail->right = root ; 
            tail = root ; 
        }
        return NULL ; 
    }
    // left subtree
    root->left = convertToDLLUtil(root->left , head , tail ) ;
    // right subtree 
    root->right = convertToDLLUtil(root->right , head , tail ) ;
    return root ; 
}

Node * convertToDLL(Node *root){
    Node *head = NULL , *tail = NULL ; 
    convertToDLLUtil(root , head , tail ) ;
    return head ; 
}
