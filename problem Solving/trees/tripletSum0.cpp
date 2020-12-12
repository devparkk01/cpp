/*Given a Binary Search Tree (BST), write a function isTripletPresent() that returns true
 if there is a triplet in given BST with sum equals to 0, otherwise returns false.

Other variation of this problem is to find if there is a triplet having sum k .
Approach will be same .

*/


/*  First approach
Do inorder traversal and store the elements in an array,then find the triplet from this array
using two pointer approach

Time : O(n^2) , space : O(n)
*/
void inorder(node *root , vector<int>&in) {
	if (!root)  return ;
	inorder(root->left , in ) ;
	in.push_back(root->key ) ;
	inorder(root->right , in ) ;

}

bool isTripletPresent(node *root) {
	vector<int>in ; in.reserve(100) ;
	inorder(root , in ) ;

	int n = in.size() ;
	int j ,  k ; int val ;
	for (int i = 0 ; i <= n - 3 ; ++i ) {
		j = i + 1 ; k = n - 1;
		val = (-in[i]) ;
		while ( j < k ) {
			if (in[j] + in[k] == val) return true ;
			else if ( in[j] + in[k] < val ) j++ ;
			else k-- ;
		}
	}
	return false ;

}

/* Second Approach

convert this BST to a doubly linked list . so our original BST will be lost .
We can do two pointer approach to find if there is a triplet present or not .
space : O(h)  recursive stack space only , since we're not using any extra memory
for DLL. time : O(n)

*/

void bstTodllUtil (node *root , node *&head , node *&tail  ) {
	if (!root) return ;
	bstTodllUtil(root->left , head , tail  ) ;
	if ( head == NULL ) {
		head = root ; tail = root ;
	}
	else {
		tail->right = root ;
		root->left = tail ;
		tail = root ;
	}
	bstTodllUtil(root->right , head , tail ) ;
}


bool isTripletPresent(node *root ) {
	node *head = NULL , *tail = NULL ;
	bstTodllUtil(root , head , tail ) ;

	head->left = NULL ; tail->right = NULL ;

	node *first = head , *second , *third ;

	if ( head == tail ) return false ;
	while (first->right != tail ) {
		int val = (-first->key)  ;
		second = first->right ; third = tail ;
		while (second != third ) {
			if (second->key + third->key == val ) return true ;
			else if (second->key + third->key < val) second = second->right ;
			else third = third->left ;
		}
		first = first->right  ;
	}
	return false  ;
}
