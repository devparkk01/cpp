/*
given the head of the node , find the nth node from the last 
1->2->4->8->7->9->3->NULL 
length = 7
if n = 1 , return 9 
if n = 2 , return 7
if n = 3 , return 8
if n = 4 , return 4
if n = 5 , return 2
if n = 6 , return 1
if n >=7 , return NULL 



*/

#include<iostream>
#define endl '\n'

using namespace std ; 

class Node {
    public :
    int data  ;
    Node * next ; 

    Node(int data ) {
        this->data = data ; 
        next = nullptr ; 
    }
} ; 

class LinkedList {
    public :
    Node* head ; 

    LinkedList() {
        head = nullptr ; 
    }
} ;

Node * nthNodeFromEnd (Node * head , int n  ) {
    Node * curr = head ; 
    Node * follower = head ; 
// both pointer moves one node at a time 

// first step : move curr node by exacly n position from the beginning 
    for (int i = 0 ; i < n ; ++i ){
        if ( curr == nullptr )
            return nullptr ; //if length of the list is n or less than n , then curr will become nullptr and return it
        curr = curr->next ; 
    }
    while ( curr->next != nullptr ) {
        curr = curr->next ; 
        follower = follower->next ; 
    }
    return follower ;  // follower is the desired node  
}

// creating linked list from array
Node * createList ( Node * head , int * arr , int size ) {
    head = new Node(arr[0]) ; 
    Node * curr = head ; 
    for (int i = 1 ; i < size ; ++i ) {
        curr->next = new Node(arr[i])  ; 
        curr = curr->next ; 
    }
    return head ; 
}


int main () {
    LinkedList list = LinkedList() ;
    int arr[] = {1,2,4,8,7,9,3} ;
    list.head = createList(list.head , arr  , sizeof(arr)/sizeof(arr[0])) ; 

    Node * elem = nthNodeFromEnd(list.head , 4) ;
    cout << "Fourth node from the last : " << elem->data << endl; 
    elem = nthNodeFromEnd(list.head , 2) ; 
    cout << "Second node from the last : " << elem->data << endl; 
    elem = nthNodeFromEnd(list.head , 6) ; 
    cout << "Sixth node from the last : " << elem->data << endl; 


    return 0 ; 
    
}


