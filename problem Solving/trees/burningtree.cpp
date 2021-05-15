/*
https://practice.geeksforgeeks.org/problems/burning-tree/1#


This question is very easy , if you're able to solve , nodes at a distance k problem .


*/


struct cell {
	Node * c ; int t ;
};


class Solution {
public:
	int minTime(Node* root, int target)
	{
		// Your code goes here
		Node *temp = find(root , target ) ;
		if (temp == NULL ) return -1 ;
		unordered_map<Node *, Node * > um ;
		parent (root , NULL , um ) ;
		unordered_set<Node * > us ;
		queue<cell>q ;
		q.push({temp , 0 } ) ;
		Node *curr ; int t ;

		while (!q.empty()) {
			curr = q.front().c ; t = q.front().t;
			q.pop() ;
			if (curr->left != NULL && us.find(curr->left) == us.end()) {
				q.push({curr->left , t + 1 }) ;
				us.insert(curr->left ) ;
			}
			if ( curr->right != NULL && us.find(curr->right ) == us.end()) {
				q.push({curr->right , t + 1 }) ;
				us.insert(curr->right ) ;
			}
			if ( um[curr] != NULL && us.find(um[curr]) == us.end()) {
				q.push({um[curr] , t + 1 }) ;
				us.insert(um[curr]) ;
			}
		}
		return t ;

	}

	Node * find(Node * root , int target ) {
		if ( root == NULL ) return root ;
		if ( root->data == target ) return root  ;
		else {
			Node * left = find(root->left, target ) ;
			if ( left ) return left ;
			Node * right = find(root->right , target ) ;
			if ( right ) return right ;
			return NULL ;
		}
	}
	void parent (Node *root , Node *p , unordered_map<Node * , Node * > &um) {
		if ( root != NULL ) {
			um[root ] = p ;
			parent(root->left , root , um) ;
			parent(root->right , root , um) ;
		}
	}
};