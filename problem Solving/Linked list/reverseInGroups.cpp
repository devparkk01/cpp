/*Given a linked list . The task is to reverse every k nodes (where k is an input to the function)
 in the linked list.
1-2-3-4-5-6-7-8-NULL , k = 3 
output : 3-2-1-6-5-4-8-7-NULL 

1-2-3-4-5-NULL , k = 5 
5-4-3-2-1-NULL 

1-2-3-4-NULL , k = 6 
4-3-2-1-NULL 
*/
#include<bits/stdc++.h>
using namespace std  ; 

class Node {
	public : 
	int data ; 
	Node * next ; 
	Node(int data ) {
		this->data = data ; 
		next = NULL;  
	}
} ; 

// time : O(n) , space : O(1) , where n is the total nodes in the list . 

Node * reverseInGroups (Node * head , int k ) {
	Node * curr= head , *prev = NULL , *next ; 
	int i = 0; 
	// reverse k nodes 
	while ( curr != NULL && i < k ) {
		next = curr->next;
		curr->next = prev ; 
		prev = curr ; 
		curr = next ; 
		i++ ; 
	}
	if ( curr != NULL) {// recursive call 
		head->next = reverseInGroups(curr , k ) ; 
	}
	return prev ; // prev is the new head  
}