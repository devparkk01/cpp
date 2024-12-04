/*spiral order traversal is same as zig zag traversal . It's just a variation of level order traversal .
			---1---
			↓     ↓
		 ---2---  3---
		 ↓	   ↓	 ↓
		 4	   5   	 6

zigzagTraversal : 1    2 3   6 5 4 
reverseZigzagTraversal : 1   3 2   4 5 6

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

/*we need two stacks ,s1 and s2 . We'll pop items from one stack and push its children into 
the other stack. 
when to push left child first and when to push right child first .
consider any level , do you want left most node first or right most node first in the traversal . 
If you want left most node first then this node should be popped first from the other stack(so that
it will be printed first )  , that means this node should be pushed at last into the other 
stack(then only you can pop it first ) , therefore  push right child first then push left child . 
Logic will be similar if you want right most node first in any level of the traversal .  
You want right most node first then this node must be popped first from the other stack , that means
you must push this node at last . so push left child first then right child . 

*/


void zigzagTraversal(Node *root ) {
	if ( root == NULL ) return ; 
	stack<Node*> s1 ; stack<Node*> s2 ; 
	s1.push(root) ; Node * temp ; 
// 	 until both stacks become empty 
	while (!s1.empty() || !s2.empty()) {
		while (!s1.empty() ) {
			temp = s1.top() ; 
			s1.pop() ; 
			cout << temp->data << " " ;
			if ( temp->right  ) s2.push(temp->right ) ;
			if (temp->left ) s2.push(temp->left) ; 
			// first right child then left child 
		}
		while(!s2.empty()) {
			temp = s2.top() ;
			s2.pop() ;
			cout << temp->data << " " ; 
			if ( temp->left) s1.push(temp->left ) ;
			if (temp->right) s1.push(temp->right ) ; 
			// first left child then right child 
		}


	}
}

void reverseZigzagTraversal(Node *root ) {
	if (root == NULL ) return ; 
	stack<Node*> s1 ;
	stack<Node*>s2 ;  s1.push(root) ;
	Node * temp ; 

// 	 until both stacks become empty 
	while (!s1.empty() || !s2.empty() ) {
		while (!s1.empty()) {
			temp = s1.top() ; 
			s1.pop() ; 
			cout << temp->data << " " ; 
			if ( temp->left ) s2.push(temp->left ) ; 
			if (temp->right ) s2.push(temp->right ) ; 
			// first left child then right child  
		}
		while (!s2.empty()) {
			temp = s2.top() ; 
			s2.pop() ;
			cout << temp->data << " " ;
			if (temp->right ) s1.push(temp->right ) ;
			if (temp->left ) s1.push(temp->left ) ; 
			// first right child then left child 
		}
	}

}