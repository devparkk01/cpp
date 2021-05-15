

struct Node {
	int data;
	Node *next ;
};

/* time : O(n + m ) , n is the no of node in first list , m is the no of node in second list

*/


Node *mergeList(Node *head1 , Node*head2) {
	Node * mergedHead , *curr , *next1 = head1 , *next2 = head2  ;
	if ( head1->data <= head2->data ) {
		mergedHead = head1 ;
		curr = head1 ;
		next1 = next1->next ;
	}
	else {
		mergedHead = head2 ;
		curr = head2 ;
		next2 = next2->next ;
	}

	while (next1 != NULL && next2 != NULL ) {
		if ( next1->data <= next2->data ) {
			curr->next = next1 ;
			curr = curr->next ;
			next1 = next1->next ;
		}
		else {
			curr->next = next2 ;
			curr = curr->next ;
			next2 = next2->next  ;
		}
	}

	curr->next = (next1 != NULL) ? next1 : next2 ;
	return mergedHead ;

}