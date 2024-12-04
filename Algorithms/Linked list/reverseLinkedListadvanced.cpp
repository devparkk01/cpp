/*
Reverse a linked list from position B to C . Do it in-place and in one-pass.
*/

#include<iostream>
using namespace std ; 
class Node {
    public : 
    int data ; 
    Node *next ; 

    Node(int data) {
        this->data = data ; 
        next = NULL ; 
    }
};

Node* reverseBetween(Node* A, int B, int C) {
    Node *curr = A , *last = A , *precurr = NULL;
    if ( B == C) return A ; // No need to reverse 
    for (int i = 0 ;i < C ; i++ ) last = last->next ; 
    // last will point to the node after Cth node , i.e ,C+1 th node 
    
    for (int i = 0 ;i <B-1 ; i++) {
        precurr = curr ; 
        curr = curr->next  ; 
    }// precurr points at  B-1th node and curr points at Bth node  

    Node *next, *prev = last ; // prev = last is very important  
    while (curr != last ) {
        next = curr->next ; 
        curr->next = prev ; 
        prev = curr ; 
        curr = next ; 
    }
    if ( precurr != NULL ) precurr->next = prev ; 
    else A = prev ;
    // precurr will be NULL only if  B is 1 , in that case prev becomes the head of the list  ; 

    return A ; 
}

