/*Given a Binary Tree, print Right view of it. 

Right view of following tree is 1 3 7 8.
         1
       /   \
     2       3
   /   \    /  \
  4     5  6    7
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
first approach :The right view contains all nodes that are last nodes in their levels. 
A simple solution is to do level order traversal and print the last node in every level.
time : O(n) ,space : O(max nodes in a level )

void rightView (Node *root ) {
	if (root == NULL ) return ; 
	queue<Node*>q ; q.push(root) ; 
	Node*curr ; int size ; 

	while (!q.empty() ) {
		size = q.size() ; 
		for (int i = 0 ; i < size ; ++i ) {
			curr= q.front() ; q.pop() ;
			if (curr->left ) q.push(curr->left ) ; 
			if (curr->right) q.push(curr->right ) ; 
			if (i == size - 1 )
				cout << curr->data << " " ; 
		}
	}
}

*/

/* second approach ( recursive )
time : O(n) ,space : O(d)
*/

void rightViewUtil (Node *root , int level , int * maxLevel )  ;

void rightView (Node * root ) {
	if (root == NULL ) return ; 
	int maxLevel = 0 ;
	rightViewUtil(root , 1 , &maxLevel) ; 
}

void rightViewUtil (Node *root , int level , int * maxLevel ) {
	// level is the current level . maxLevel is the max Level seen so far .
	// base case 
	if (root == NULL) return ; 
	// if we haven't seen this level 
	if ( *maxLevel < level ) {
		cout << root->data << " " ;
		*maxLevel = level ; 	
	}
	rightViewUtil(root->right , level + 1 , maxLevel ) ; 
	rightViewUtil(root->left , level + 1 , maxLevel) ; 
	// first go through the right subtree then left subtree .
}