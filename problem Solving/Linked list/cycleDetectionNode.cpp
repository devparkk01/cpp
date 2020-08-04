/*
Write a function that takes in the head of a linked list that contains a loop . The function should return 
the node from which the loop originates in constant space . The linked list surely contains a loop 

1 -> 2 -> 4 ->3->5->9->10->
              ↑___________↓     SHOULD RETURN 3 


1 -> 2 -> 7 ->3->5->9->
                 ↑____↓ 
                                SHOULD RETURN 5 
*/




#include<iostream>
#define endl '\n'

using namespace std ; 


class Node {
    public :
    int data ;
    Node * next ; 
    Node (int data) {
        this->data = data ; 
        next = nullptr; 
    }
}; 

class LinkedList {
    public:
    Node * head ;
    LinkedList() {
        head = nullptr ; 
    }
} ;

Node * cycleDetectionNode (Node * head ) {
    Node* fast = head ; Node * slow = head ;
    while  (true) {
        slow = slow->next ;
        fast = fast->next->next ; 
        if ( fast == slow  ) {
            break ; 
        }
    }
    slow = head ; 
    while ( slow != fast ) {
        slow =  slow->next ; 
        fast = fast->next ; 
    }
    return slow ; 

}
/*
time : O(n) and space O(1)



*/

int main () {
    LinkedList list = LinkedList() ; 
    list.head = new Node(1) ; 
    list.head->next = new Node(2) ; 
    list.head->next->next = new Node(4) ; 
    list.head->next->next->next  = new Node(3) ; 
    list.head->next->next->next->next = list.head->next->next ; // making a cycle 

    Node * loopNode = cycleDetectionNode(list.head ) ; 
    cout << loopNode->data << endl; 

    return 0 ;
}