/* We have to remove all duplicate nodes from a linked list ,
Given that linked list consists of atleast 1 node . 
  */

#include<bits/stdc++.h> 
using namespace std ; 

class Node {
	public :
	int data ; 
	Node*next ; 
	Node(int data) {
		this->data = data ; 
		next = NULL ; 
	}
} ; 

/*part 1 , if list is sorted 
 2-4-4-5-NULL => 2-4-5-NULl
 2-2-2-2-2 => 2-NULL 

 time: O(n) ,space : O(1)
*/
Node* removeDuplicatesFromSorted(Node *head ) {
	Node*curr = head ; 
	Node*next = curr->next ; 

	while (next != NULL) {
		if ( next->data == curr->data) {
			next = next->data ; 
		}
		else {
			curr->next = next ; 
			curr = next ; 
			next = curr->next ; 
		}
	}
	curr->next = NULL ; //very important  (don't forget )
	return head ; 
}

/*part 2 , if list is not sorted 
 2-3-2-5-3-4-7-NULL  => 2-3-5-4-7-NULL 
 2-6-6-2-NULL => 2-NULL 

 time : O(n) , space : O(n)
*/

Node * removeDuplicatesFromUnsorted(Node * head ) {
	unordered_set<int> uset ;
	uset.insert(head->data)  ; 

	Node*curr = head ; Node*next = curr->next ; 
	while ( next != NULL ) {
		if ( uset.find(next->data) != uset.end()) {
			next = next->next ; 
		}
		else {
			uset.insert(next->data) ; 
			curr->next = next ; 
			curr = next ; 
			next = curr->next ; 
		}
	}
	curr->next = NULL ; 
	return head ; 
}
