#include <iostream>
using namespace std;

class Node {
	public : 
	int data ; 
	Node*next ; 
	Node(int data ) {
		this->data = data ; 
		next = NULL ; 
	}
}; 

void print(Node  * A ) {
	Node * curr = A ;
	while ( curr != NULL) {
		cout << curr->data <<  " " ;
		curr = curr->next ; 
	}
	cout << endl; 
}

Node* reverse(Node* A, int B, int C) {
    Node *curr = A , *curr2 = A , *head = NULL ; 
    if ( B==C) return A ; 
    for (int i = 0 ; i < B-1 ; i++) {
        head = curr ; 
        curr = curr->next ; 
    }
    for (int i = 0 ; i< C ; i++) {
        curr2 = curr2->next ; 
    }
    Node *next = NULL , *prev = curr2 ; 
    while (curr!= curr2 ) {
        next = curr->next  ;
        curr->next = prev ;
        prev = curr ; 
        curr = next ; 
    }
    head->next = prev ; 
    return A ; 
    
}

int main() {
	Node * head = new Node(1) ; 
	head->next = new Node(2) ; 
	head->next->next = new Node(3) ; 
	print(head) ; 
	head=  reverse(head , 1, 2 ) ; 
	print(head) ; 
	// // your code goes here
	return 0;
}
