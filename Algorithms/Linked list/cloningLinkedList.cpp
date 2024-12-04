/*We are given a double linked list with one pointer of each node pointing to the next node just
like in a single linked list. The second pointer however can point to any node in the list 
and not just the previous node . We've to clone this linked list . 	

No extra space will be used here . 
time : O(n) , space : O(1) 

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
		curr = curr->next->next ; // or temp->next 
	}
	
    curr = head ; 
	while (curr != NULL ) {
	    temp = curr->next ; 
		temp->arb = (curr->arb) ? curr->arb->next : NULL ; 
		curr = curr->next->next ; 
	}
	curr = head ; 
	Node *copyHead = curr->next ; 
	temp = copyHead ; 

	while (curr != NULL ) {
		curr->next = (curr->next ) ? curr->next->next : NULL ; 
		curr = curr->next ; 

		temp->next = (temp->next ) ? temp->next->next : NULL ;
		temp = temp->next ;
	}
	return copyHead ;   

}

void print(Node *head ) {
	while (head ) {
		cout << head->data << " " ; 
		head = head->next ; 
	}
	cout << endl; 
}

// for printing  arbitraty pointers of the node
void printArb ( Node *head ) {
	Node*curr = head ;
	while(curr != NULL ) {
		cout << curr->data << " -> " ; 
		if ( curr->arb) {
			cout << curr->arb->data << endl ; 
		}
		else cout << "NULL " << endl;
		curr = curr->next ;  
	}
}



signed main() {
	Node *list =  new Node(10) ;
	list->next = new Node(20) ;
	list->next->next = new Node(30) ;
	list->arb = list->next->next ; 
	list->next->arb = list ; 

	cout << "Original list " << endl; 
	print(list ) ; 
	printArb(list);

	Node * copy = clone(list ) ;
	cout << "Copy list " << endl ; 
	print(copy ) ;
	printArb(copy) ;


	return 0 ; 
}