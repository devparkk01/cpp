/*Given a BST and an integer. Find the least absolute
 difference between any node value of the BST and the given integer.

time : O(h) , space : O(h) recursive space , where h is the height of the tree .
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

// utility function 
int util (Node *root , int nearest , int k ) {
    if (root == NULL ) return abs(k - nearest ) ;
    if ( abs(root->data - k ) < abs(nearest - k )) {
        nearest = root->data ; // update nearest element 
    }
    if (root->data == k ) return 0 ; // found the exact element 
    if (root->data < k ) 
        return util(root->right , nearest , k ) ;
    if (root->data > k ) 
        return util (root->left , nearest , k ) ; 
}

int minDiff(Node *root, int k )
{
    return util(root , root->data , k) ; 
}