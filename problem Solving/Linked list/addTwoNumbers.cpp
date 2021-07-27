/*
https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

best test case to think about :
9->4->5->6
   8->2->4

output  : 1->0->2->8->0

*/

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
	first = reverse(first) ;
	second = reverse(second) ;
	Node * head = NULL , * curr = NULL ;
	int c = 0 , sum ;
	while (first && second) {
		sum = first->data + second->data + c ;
		c = sum / 10 ;
		sum = sum % 10 ;
		if (head == NULL) {
			head = new Node(sum) ;
			curr = head ;
		}
		else {
			curr->next = new Node(sum) ;
			curr = curr->next ;
		}
		first = first->next ;
		second = second->next ;

	}
	while (first) {
		sum = first->data + c ;
		c = sum / 10 ;
		sum = sum % 10 ;
		curr->next = new Node(sum) ;
		curr = curr->next ;
		first = first->next ;
	}

	while (second) {
		sum = second->data + c ;
		c = sum / 10 ;
		sum = sum % 10 ;
		curr->next = new Node(sum) ;
		curr = curr->next ;
		second = second->next ;
	}
	if (c != 0 ) {
		curr->next = new Node(c) ;
	}

	head = reverse(head) ;
	return head ;

}
Node * reverse(Node * head) {
	Node *curr  = head , *prev = NULL , *next = NULL ;
	while (curr) {
		next = curr->next ;
		curr->next = prev ;
		prev = curr ;
		curr = next ;
	}
	return prev ;
}