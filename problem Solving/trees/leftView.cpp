/*Given a Binary Tree, print Left view of it. 

Left view of following tree is 1 2 4 8.

          1
       /    \
     2        3
   /   \    /   \
  4     5   6    7
   \
    8   

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
/*
first approach :The left view contains all nodes that are first nodes in their levels. 
A simple solution is to do level order traversal and print the first node in every level.
time : O(n) ,space : O(max nodes in a level )

void leftView(Node *root ) {
	if ( root == NULL) return ; 
	queue<Node*> q ; q.push(root ) ;
	Node *curr ; int size ;
	while (!q.empty() ) {
		size = q.size() : 
		for (int i = 0 ; i < size ; ++i ) {
			curr = q.front() ; q.pop() ; 
			if ( curr->left ) q.push(curr->left ) ; 
			if ( curr->right ) q.push(curr->right ) ; 
			if ( i == 0 ) {
				cout << curr->data << " " ; 
			}
		}
	}
}
*/

/* second approach ( recursive )
time : O(n) ,space : O(d)
*/

void leftViewUtil (Node * root , int level , int * maxLevel ) ;

void leftView (Node *root ) {
	if (root == NULL) return; 
	int maxLevel = 0 ; 
	leftViewUtil(root , 1 , &maxLevel) ;
	// sending the address of maxLevel 
}

void leftViewUtil (Node * root , int level , int * maxLevel ) {
	// level is the current level . maxLevel is the max Level seen so far .
	if (root == NULL ) return ; // base case 
	// if we haven't seen this level 
	if ( *maxLevel < level) {
		cout << root->data << " " ;
		*maxLevel = level ;   // now we've seen this level . 
	}
	leftViewUtil(root->left  , level + 1 , maxLevel) ; 
	leftViewUtil (root->right , level + 1 , maxLevel) ; 
	// first go through the  left subtree then right subtree . 
}


