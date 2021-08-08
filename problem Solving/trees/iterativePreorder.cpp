


vector<int> preOrder(Node* root)
{
	stack<Node *>s ;
	Node *curr = root  ;
	vector<int>ans ;

	while (1) {

		if (curr == NULL) {
			if (s.empty()) break;
			else {
				curr = s.top() ; s.pop() ;
				curr = curr->right ;
			}
		}
		else {
			// visit the node
			ans.push_back(curr->data) ;
			// push the node into stack so that we can visit its right sub tree later
			s.push(curr) ;
			// visit curr node's left subtree
			curr = curr->left ;

		}
	}
	return ans ;
}