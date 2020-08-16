/*Given a binary tree. Check whether it is a BST or not. 

time : O(n ) , and space : O(d) ,where d is the depth of the tree .
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

// helper function 
bool validateHelper (Node * root , int Min , int Max ) ;

bool validate(Node * root ) {
	return validateHelper(root , INT_MIN , INT_MAX) ; 
}
/* for each node there is a minimum and maximum that it can have . root can have min value of -inf while 
max value of +inf. but the left child of root can have max value of root->data , it can not exceed that. 
while right child of root node can have min value of root->data .it can't be less than that. 
so for each node we pass maximum and minimum that it can have . if it violates this property we return
false . 

*/
bool validateHelper (Node * root , int Min , int Max ) {
	if ( root == NULL )return true ; // NULL is a valid node 
	if ( root->data <= Min || root->data >= Max) return false ;
	else {
		if (validateHelper(root->left , Min , root->data )) {
			if ( validateHelper(root->right , root->data, Max )) 
				return true ; 
			else return false ; 
		}
		else return false ; 
	}
}