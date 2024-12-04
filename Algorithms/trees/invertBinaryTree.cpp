/*Given a Binary Tree, convert it into its mirror( same as inverting a binary tree )

		input : 
		     4                 
		   /   \ 
		  2     7      
		 / \   / 
		1   3 6 

		output : 
		     4
		   /   \
		  7     2
		   \   / \
		    6 3   1

*/

/*we can do recursively , time : O(n) , space : O(d) , recursive space , 
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

void invert(Node * root ) {
	if (root != NULL ) {
		// Node *temp = node->left ;
        // node->left =  node->right ;
        // node->right = temp ;
		swap(root->left , root->right ) ; 
		invert(root->left ) ; 
		invert(root->right ) ; 
	}
}
