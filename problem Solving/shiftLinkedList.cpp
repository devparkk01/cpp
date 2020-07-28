/*Write a function that takes in the head of a singly linked list and an integer `k` , shifts the list in place
( i.e , doesn't create a brand new list ) by `k` position and returns its new head . 

   0-1-2-3-4-5-NULL 
k = 1 , 5-0-1-2-3-4-NULL 
k = -1 , 1-2-3-4-5-0-NULL
k = 2 , 4-5-0-1-2-3-NULL 
k = -2 , 2-3-4-5-0-1-NULL 
if k > 0 , shifting is clock wise 
if k < 0 , shifting is anti clock wise 
*/

#include<iostream>
using namespace std ; 
class Node {
    public : 
    int data ; 
    Node  * next ; 

    Node(int data ) {
        this->data = data ; 
        next = NULL ;
    }
} ;
/*
four pointers we require , head = points to the current head , tail = points to the current tail 
newHead = points to the new head , newTail = points to the new tail 
 time : O(n) and 
*/
Node *shiftList ( Node * head , int k ) {
    // find the length of the list as well as get the pointer to the tail of the list 
    Node*tail = head ; int length  = 1 ; 
    while ( tail->next != NULL) {
        tail = tail->next ; 
        length++ ; 
    }
    // (tailPos)th node is the node which will become newTail, and the node next to newTail will become newHead 
    int tailPos = abs(k) % length ; 
    if (tailPos == 0 ) return head ; 
    tailPos = ( k > 0 )  ? length - tailPos  :  tailPos ; 

    Node *newTail = head , *newHead  ; 
    for (int i = 1 ; i < tailPos ; ++i) {
        newTail = newTail->next ; 
    }
    newHead = newTail->next ; 
    tail->next = head ; 
    newTail->next = NULL ; 
    head = newHead ; 
    return head ; 
}

