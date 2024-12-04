/* Here , we will see different types of level order traversal of a binary tree. 

			---1---
			↓     ↓
		 ---2---  3---
		 ↓	   ↓	 ↓
		 4	   5   	 6 

levelOrderLR - > 1 2 3 4 5 6 
levelOrderRL - > 1 3 2 6 5 4
ReverselevelOrderLR - > 4 5 6 2 3 1
ReverselevelOrderRL - > 6 5 4 3 2 1

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

// time O(n) , space : O(n)

void levelOrderLR(Node*root ) {
	if (! root )return ;
	queue<Node *>q ; 
	q.push(root) ; Node * temp ; 
	while (!q.empty())  {
		temp = q.front() ;
		q.pop() ;  
		cout << temp->data << " " ;
		if ( temp->left ) q.push(temp->left ) ; 
		if ( temp->right) q.push(temp->right) ; 
		// first push left child then right child 
	}
}

// time O(n) , space : O(n)
void levelOrderRL(Node* root ) {
	if (! root )return ;
	queue<Node *>q ; 
	q.push(root) ; Node * temp ; 
	while (!q.empty())  {
		temp = q.front() ; 
		cout << temp->data << " " ;
		if (temp->right ) q.push(temp->right) ; 
		if ( temp->left ) q.push(temp->left ) ; 
		// first push right child then left child 
	}
}

// time O(n) , space : O(n)
// it's actually the reverse of levelOrderRL .
void ReverselevelOrderLR (Node * root ) {
	if (! root )return ;
	queue<Node*>q ; 
	stack<int> stk ; 
	q.push(root) ; Node * temp ; 
	while (!q.empty() ) {
		temp = q.front() ; 
		q.pop() ;
		stk.push(temp->data) ; 
		if (temp->right ) q.push(temp->right ) ;
		if ( temp->left ) q.push(temp->left ) ;
		// first right then left  
	}
	while (!stk.empty() ) {
		cout << stk.top() << " " ;
		stk.pop() ; 
	}
}

// time O(n) , space : O(n)
// it's actually the reverse of levelOrderLR 
void ReverselevelOrderRL ( Node * root ) {
	if (! root )return ;
	queue<Node *> q; 
	q.push(root ) ; 
	stack<int>stk ;   Node * temp ;
	while (!q.empty() ) {
		temp = q.front() ; 
		q.pop() ; 
		stk.push(temp->data) ; 
		if (temp->left ) q.push(temp->left ) ; 
		if (temp->right ) q.push(temp->right ) ; 
		// first left then right 
	}
	while (!stk.empty() ) {
		cout << stk.top() << " " ; 
		stk.pop() ; 
	}

}