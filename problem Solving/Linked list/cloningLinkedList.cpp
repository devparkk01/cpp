/*We are given a double linked list with one pointer of each node pointing to the next node just
like in a single linked list. The second pointer however can point to any node in the list 
and not just the previous node . We've to clone this linked list . 	
*/


#include<bits/stdc++.h>
using namespace std ; 


class Node {
public:
	int data ; Node *next , *arb ;
	Node(int data ) {
		this->data = data ; 
		next = NULL ; arb = NULL ; 
	}
}; 

Node *clone ( Node *head) {
	Node *curr = head , *temp ; 
	while (curr != NULL ) {
		temp = new Node(curr->data ) ;
		temp->next = curr->next ; 
		curr->next = temp ; 
		curr = temp->next ; 
	}
	
    curr = head ; 
	Node *curr1  ; 

	while (curr != NULL ) {
	    curr1 = curr->next ; 
		if ( curr->arb) {
			curr1->arb = curr->arb->next ; 
		}
		else curr1->arb = NULL ; 
		curr = curr->next->next ; 
	}
	curr = head ; 
	Node *newHead = curr->next ; 
	curr1 = newHead ; 

	while (curr != NULL ) {
		curr->next = (curr->next ) ? curr->next->next : NULL ; 
		curr = curr->next ; 

		curr1->next = (curr1->next ) ? curr1->next->next : NULL ;
		curr1 = curr1->next ;
	}
	return newHead ;   

}

void print(Node *head ) {
	while (head ) {
		cout << head->data << " " ; 
		head = head->next ; 
	}
	cout << endl; 
}



signed main() {
	Node *list =  new Node(10) ;
	list->next = new Node(20) ;
	list->next->next = new Node(30) ;

	print(list); 
	Node *copy = clone(list ) ;
	print(copy) ; 

	return 0 ; 
}