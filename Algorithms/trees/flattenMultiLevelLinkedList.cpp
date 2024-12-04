/*
https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

*/


class Solution {
public:
	Node* flatten(Node* head) {
		util(head ) ;
		return head ;
	}

	Node *util(Node *head ) {
		Node *curr = head  , *next, *prev , *child  ;
		while (curr != NULL ) {
			if (curr->child != NULL ) {
				next = curr->next ;
				child = curr->child ;
				prev = util(child) ;
				curr->next = child ;
				child->prev = curr ;
				curr->child = NULL ;


				if (next != NULL ) {
					prev->next = next ;
					next->prev = prev ;
				}
				curr = next ;
			}
			else {
				prev = curr ;
				curr = curr->next ;
			}
		}
		return  prev  ;

	}
};