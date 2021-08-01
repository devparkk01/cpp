/*
https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1#

time : O(n * n) , space : O(n)
*/



Node * building(int in[] , int post[] , int inS , int inE , int &curr ) {
	if (inS > inE) return NULL ;
	Node *root = new Node(post[curr]) ;
	int mid = -1 ;
	for (int i = inS ; i <= inE ; ++i) {
		if (in[i] == post[curr]) {mid = i ; break ; }
	}
	curr-- ;
	root->right = building(in , post , mid + 1 , inE , curr ) ;
	root->left = building(in , post , inS , mid - 1 , curr ) ;

	return root ;
}
Node *buildTree(int in[], int post[], int n) {
	// Your code here
	int curr = n - 1  ;
	return building(in , post , 0 , n - 1 , curr );
}