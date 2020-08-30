#include <bits/stdc++.h>
using namespace std;


class Node {
	public : 
	int data ;
	Node *next ;
	Node (int data ) {
		this->data = data ; 
		next = NULL ;
	}
} ; 


void print(Node *head ) {
	Node *curr = head ;
	while (curr != NULL ) {
		cout << curr->data << " " ;
		curr = curr->next ; 
	}
	cout << endl;  
}


void change (Node * &head ) {
	head = head->next ; 
	print(head ) ; 
}


signed  main() {
	Node *head = new Node(10) ; 
	head->next = new Node(20) ;
	head->next->next = new Node(30) ; 

	print(head ) ; 
	change(head ) ;
	print(head ); 

	
	return 0;
}

