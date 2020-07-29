/* Given a linked list. The task is to remove the Nth node from the end of the linked list. 

Input : 1->2->3->4->5 , N = 2
Output : 1->2->3->5

Input : 7->8->4->3->2 , N = 1
Output : 7->8->4->3

Input : 7->8->4->3->2 , N = 5
Output : 8->4->3->2
*/

class Node {
public:
	int data ; 
	Node*next ; 
	Node (int data ) {
		this->data = data ; 
		next = NULL ; 
	}
}; 

Node * removeNthNode (Node * head ,  int n ) {
	Node *temp = head ;
	for (int i = 0 ;i < k ; ++i){
		temp = temp->next ; 
	}
// temp == NULL means we need to delete the head of the list . 
	if ( temp == NULL ) return head->next ; 
	
// curr will point to the node to be deleted . prev is the previous node of the curr . 
	Node *curr = head , *prev = NULL ; 
	while ( curr != NULL ) {
		prev = curr ; 
		curr = curr->next ; 
		temp = temp->next ; 
	}
	prev->next = curr->next ; 
	return head;  
}