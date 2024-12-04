/*Given a singly linked list: A0→A1→…→An-1→An, reorder it to: A0→An→A1→An-1→A2→An-2→…

For example: Given 1->2->3->4->5 its reorder is 1->5->2->4->3.
1->7->3->4   its reorder is 1 -> 4 -> 7 -> 3 

Note: It is recommended do this in-place without altering the nodes' values.

time : O(n) , space : O(1)
*/

#include<iostream>
using namespace std ; 

class Node {
	public :
	int data ; 
	Node *next ; 
	Node(int data ) {
		this->data = data ; 
		next = NULL ; 
	}
} ; 

Node * reverse(Node * head ) ; 

void reorderList(Node* head) {
	if (head == NULL || head->next == NULL ) return ; 

	Node *first = head , *second = head , *prev = NULL ; 
	while ( first != NULL && first->next != NULL ) {
		prev = second ; 
		second = second->next ; 
		first = first->next->next  ; 
	}
	prev->next = NULL ;
	first = head ;  
	second = reverse(second ) ; 

	Node *next1 , *next2 ; 

	while( first->next != NULL ) {
		next1 = first->next ; 
		next2 = second->next ; 

		first->next = second ; 
		second->next = next1 ; 

		first = next1 ; 
		second = next2 ; 
	}
	first->next = second ; 
}


Node * reverse(Node * head ) {
	Node* curr = head , *prev = NULL , *next  = NULL ; 
	while (curr != NULL ) {
		next = curr->next ; 
		curr->next = prev ; 
		prev = curr ; 
		curr = next ; 
	}
	return prev ; 
}