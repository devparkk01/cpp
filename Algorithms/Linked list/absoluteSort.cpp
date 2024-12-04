/*
Given a linked list L of N nodes, sorted in ascending order based on the absolute values of its data. 
Sort the linked list according to the actual values.
Ex: Input : 1 -> -2 -> -3 -> 4 -> -5 
      Output: -5 -> -3 -> -2 -> 1 -> 4

*/

// headref is the pointer to the head node . Don't return any node . 
void sortList(Node** headref)
{
    Node * head = *(headref) ; 
    Node *curr = head->next  , *prev = head ; 
    while ( curr != NULL) {
        if ( curr->data < 0 ) {
            prev->next = curr->next ; 
            curr->next = head ; 
            head = curr ; 
            curr = prev->next ; 
        }
        else {
            prev = curr ; curr= curr->next ; 
        }
    }
    *headref = head ; 
}