/*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
If no such element exists then return -1 . 
*/

#include<bits/stdc++.h>
using namespace std ; 

class Node {
	public :
	int data ; 
	Node *left ; 
	Node *right ; 
	Node (int data ) {
		this->data = data ; 
		left = NULL ; right = NULL ; 
	}
};

/*first approach is to get inorder traversal of the tree in an array , then print (k-1)th index . 
time : O(n) , space: O(n)

void inorder(Node *root , vector<int> &v ) {
	if(root) {
		inorder(root->left , v ) ; 
		v.push_back(root->data) ; 
		inorder(root->right , v ) ;
	}
}

int kSmallest (Node *root , int k ) {
	vector<int>v ; 
	inorder(root , v ) ; 
	if ( v.size() >= k) return v[k-1 ] ; 
	else return -1 ; 
}

*/



/* second approach 
based on iterative method of inorder traversal . 
time : O(n) , space : O(d) ,d = depth of the tree . 
*/

int kSmallest (Node *root , int k ) {
	stack<Node *> s; Node * curr = root ; 
	int count = 0 ;
	while (curr != NULL || !s.empty() ) {
		while (curr != NULL ) {
			s.push(curr) ; 
			curr = curr->left ; 
		}
		// curr becomes NULL here 
		count++ ; 
		curr = s.top() ; s.pop() ;
		if (count == k ) return curr->data ;
		curr = curr->right ; 
	}
	return -1 ; // when total no of nodes are less than k .
}



