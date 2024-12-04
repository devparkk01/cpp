/*We are given a double linked list with one pointer of each node pointing to the next node just
like in a single linked list. The second pointer however can point to any node in the list 
and not just the previous node . We've to clone this linked list . 	

we will use extra space here . That's y this is not the efficient approach . for efficient approach
check cloning linked list problem .

We will be using hashmap for extra space here . 
time : O(n) , space : O(n) 
*/


#include<bits/stdc++.h>
using namespace std ; 

class Node {
public:
	int data ; Node *next , *arb ;  
	Node(int data ) {
		this->data = data ; 
		next = NULL ; 
		arb = NULL ;
	}
};

Node * cloneExtraSpace(Node *head ) {
	unordered_map<Node* , Node*> umap ; 
	Node * curr = head ; 
	Node *temp ; 
	while (curr != NULL ) {
		temp = new Node(curr->data) ; 
		umap[curr ] = temp ;
		curr = curr->next ; 
	}
	curr = head ; 
	while (curr != NULL ) {
		temp = umap[curr]; 
		temp->next = umap[curr->next] ; 
		temp->arb = umap[curr->arb] ;
		curr = curr->next ; 
	}

	return umap[head] ; // returning head of our copy list 
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

	Node * copy = cloneExtraSpace(list ) ;
	cout << "Copy list " << endl ; 
	print(copy ) ;
	printArb(copy) ;



	return 0; 
}
