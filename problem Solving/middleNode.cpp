/*
Given a linked list (singly or doubly ) find the middle node 
if length is odd return middle node  1->3->5->2->8   return 5 
if length is even return second middle node  1->3->5->2->8->1  return 2 

*/

#include<iostream>
#define endl '\n' 

using namespace std ; 

class Node {
    public : 
    int data; 
    Node* next ; 

    Node(int item) {
        data = item ; 
        next = nullptr ; 
    }
} ; 

class LinkedList {
    public : 
    Node * head ; 

    LinkedList() {
        head = nullptr ; 
    }
} ; 

Node * middleNode (Node * head ) {
    Node * slow = head  ;   // move one node at a time 
    Node * fast = head ;   // move two nodes at a time 

    while (fast != nullptr && fast->next != nullptr) {  // put fast->next after fast in the if condition 
        slow = slow->next ; 
        fast = fast->next->next ; 
    }
    // if fast == nullptr then even no of elements are there in the list 
    // if fast->next == nullptr then odd no of elements are there in the list 

    return slow ; // slow points to the middle node 

}

int main () {
    LinkedList list = LinkedList() ; 
    list.head = new Node(1) ; 
    list.head->next = new Node(3) ;
    list.head->next->next  = new Node(5) ; 
    list.head->next->next->next   = new Node(2) ; 
    list.head->next->next->next->next  = new Node(8) ; 

    Node * middle = middleNode(list.head ) ; 
    cout << "Middle node : " << middle->data <<endl ; 

    LinkedList list2=  LinkedList() ; 
    list.head->next->next->next->next->next  = new Node(1) ; 
    list2.head = list.head ;  // copy the full list 

    middle = middleNode(list2.head ) ;
    cout << "Middle Node : " << middle->data << endl ; 



    return 0 ; 



}


