/*Given a Binary search tree. Your task is to complete the function which will return the Kth largest
element without doing any modification in Binary Search Tree.

approach will be similar to kth smallest value with little bit modification . 
Iterative reverse inorder traversal . 
*/

int kthLargestValue (Node *root ) {

	stack<Node*> s ; 
	Node *curr = root ; int count = 0 ;

	while ( curr != NULL || !s.empty() ) {
		while (curr != NULL ) {
			s.push(curr) ; 
			curr = curr->right ; // traverse  right subtree
		}
		// curr becomes NULL here 
		count++ ; 
		curr = s.top() ; s.pop() ; 
		if (count == k ) {
			return curr->data ; 
		}
		curr = curr->left ; // traverse  left subtree
	}
	return  -1 ; // when no of nodes is less than k .
}

