/*
https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1#

*/

class Solution {
public:
	//Function to sort the given linked list using Merge Sort.
	Node* mergeSort(Node* head) {

		if (head == NULL) return head  ;
		mergeSortUtil(head ) ;
		return head ;
	}

	void mergeSortUtil(Node *&head ) {
		if (head == NULL || head->next == NULL) return  ; // there is atleast 1 element present

		Node *first , *second   ;
		divide(head , first , second ) ;
		mergeSortUtil(first ) ;
		mergeSortUtil(second ) ;

		head = merge(first , second ) ;


	}

	void divide(Node *head , Node *&first , Node *&second ) {
		Node *slow = head ;
		Node *fast = head->next ;
		while (fast != NULL && fast->next != NULL ) {
			fast = fast->next->next ;
			slow = slow->next ;
		}
		first = head ;
		second = slow->next ;
		slow->next = NULL ; // to mark the end of first divided list


	}

	Node * merge(Node *first , Node *second ) {
		Node *head , *curr1 = first  , *curr2 = second  , *curr   ;
		if (curr1->data < curr2->data  ) {
			head = curr1 ;
			curr = head ;
			curr1 = curr1->next ;
		}
		else {
			head  = curr2 ;
			curr = head ;
			curr2 = curr2->next ;
		}

		while (curr1 != NULL && curr2 != NULL) {
			if (curr1->data < curr2->data ) {
				curr->next = curr1 ;
				curr1 = curr1->next ;
				curr = curr->next ;
			}
			else {
				curr->next = curr2 ;
				curr2 = curr2->next ;
				curr = curr->next ;
			}
		}

		if (curr1 != NULL ) {
			curr->next = curr1 ;
		}
		else curr->next = curr2 ;
		return head ;


	}

};