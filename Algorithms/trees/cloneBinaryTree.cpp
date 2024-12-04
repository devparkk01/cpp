/*

https://practice.geeksforgeeks.org/problems/clone-a-binary-tree/1

*/

class Solution {
public:

	Node* cloneTree(Node* tree)
	{
		unordered_map<Node *, Node *> hash ;

		createCopy(tree , hash) ;

		adjustPointers(tree , hash) ;

		return hash[tree] ;

	}

	void createCopy (Node * &tree , unordered_map<Node * , Node *> &hash ) {
		if (tree == NULL ) return ;
		else {
			Node *node = new Node(tree->data ) ;
			hash[tree] = node ;
			createCopy(tree->left , hash) ;
			createCopy(tree->right  , hash ) ;
		}
	}

	void adjustPointers(Node * &tree , unordered_map<Node * , Node *> &hash) {
		if (tree == NULL) return ;
		Node *node = hash[tree] ;

		node->random = (tree->random != NULL) ? hash[tree->random] : NULL ;
		if (tree->left ) {
			node->left = hash[tree->left] ;
			adjustPointers(tree->left , hash) ;
		}
		else node->left = NULL ;

		if (tree->right  ) {
			node->right = hash[tree->right ] ;
			adjustPointers(tree->right , hash) ;
		}
		else node->right = NULL ;



	}


};