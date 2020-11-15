/*Given a BST,  and a reference to a Node x in the BST. Find the Inorder Successor of the 
given node in the BST.
time : O(h) , h = height of the BST
space : O(1) , recursive stack will be O(h) 
*/

// Recursive solution 

Node *search(Node *root , Node *x , Node *suc ) {
    if (root == NULL ) return suc ; 
    if ( root->data <= x->data) {
        return search(root->right , x , suc ) ; 
    }
    else {
        suc = root ; 
        return search(root->left , x , suc ) ; 
    }
}

Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    Node *suc = NULL ; // suc stores inorder successor 
    return search(root , x , suc) ; 
    
}

// iterative solution 
Node * inOrderSuccessor(Node *root , Nod *x ) {
	Node *suc = NULL ; // Inorder successor 
	Node *curr = root ; 

	while (curr!= NULL ) {
		if (curr->data <= x->data ) 
			curr = curr->right ;
		else {
			suc = curr ; 
			curr = curr->left ; 
		}
	}
	return suc ; 
}
