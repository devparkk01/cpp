
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
// time : O(n) , space : O(d) , d= depth of the tree
void iterativeInorder (Node * root ) {
	if (root == NULL ) return ;
	stack<Node*> s ; Node *curr = root ;

	while (curr != NULL || !s.empty()) {
		while (curr != NULL ) {
			// push the node to the stack before visiting its left subtree
			s.push(curr) ;
			curr = curr->left ;
		}
		// curr becomes NULL here
		curr = s.top() ; s.pop() ;
		cout << curr->data << " " ;
		curr = curr->right ; /*we have already visited the node and its left subtree,now we need to
		visit its right subtree */
	}
}


vector<int> inOrder(Node* root)
{
	//code here
	vector<int>ans ;
	stack<Node *>s ;
	Node *curr = root ;
	while (1) {
		if (curr != NULL) {
			s.push(curr) ;
			curr = curr->left ;
		}
		else {
			if (s.size() > 0 ) {
				curr = s.top() ; s.pop() ;
				ans.push_back(curr->data) ;
				curr = curr->right ;
			}
			else break ;
		}
	}
	return ans ;
}
