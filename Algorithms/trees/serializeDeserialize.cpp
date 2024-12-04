/*
https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1


*/
vector<int> serialize(Node *root)
{
	vector<int>a  ;
	preOrder(root , a) ;
	reverse(a.begin() , a.end()) ;
	return a ;
}

void preOrder(Node *root , vector<int>&a) {
	if (!root ) {
		a.push_back(-1) ;
		return ;
	}
	a.push_back(root->data) ;
	preOrder(root->left, a ) ;
	preOrder(root->right , a ) ;

}

//Function to deserialize a list and construct the tree.
Node * deSerialize(vector<int> &A)
{
	int t = A.back() ;
	A.pop_back() ;
	if (t == -1 ) {
		return NULL ;
	}
	else {
		Node *n = new Node(t) ;
		n->left = deSerialize(A);
		n->right = deSerialize(A) ;
		return n ;
	}


}