/*
Given pointers to the head nodes of  linked lists that merge together at some point, 
find the Node where the two lists merge. It is guaranteed that the two head Nodes will be different, 
and neither will be NULL.


[List #1] a--->b--->c
                     \
                      x--->y--->z--->NULL
                     /
     [List #2] p--->q

    here , merge point is x 

*/

#include<iostream>
#define endl '\n'

using namespace std ; 

class Node {
    public : 
    int data ; 
    Node  * next ; 

    Node (int data ) {
        this->data = data ; 
        next = nullptr ; 
    }
};

class LinkedList {
    public : 
    Node * head ;
    LinkedList() {
        head = nullptr ; 
    }
}; 


int findMergePoint(Node * head1 , Node * head2) {
    Node * first = head1  , *second = head2 ; 
    while (first != second ) {
        first = (first->next != nullptr ) ? first->next : head2 ; 
        second = (second->next != nullptr ) ? second->next : head1 ; 
    }

    return first->data ;  // can return second->data as well 

}

/*
we will keep two pointers , first and second . first will traverse the first linked list and when it reaches the end of 
this list , i.e, the last element , it will start traversing the second linked list .
similarly second will start traversing the second linked list and when it encounters the last element of this list , it 
will start traversing the first linked list  .

time complexity  : O(m+n) , m = size of the first list , n = size  of the second list  
*/

Node * createList ( Node * head , int * arr , int size ) {
    head = new Node(arr[0]) ; 
    Node * curr = head ; 
    for (int i = 1 ; i < size  ; ++i ) {
        curr->next = new Node(arr[i])  ; 
        curr = curr->next ; 
    }
    return head ; 
}

int main() {
    LinkedList list1 = LinkedList() ; 
    LinkedList list2 = LinkedList() ; 
    list1.head = new Node(10) ; 
    list1.head->next = new Node(20) ; 
    list1.head->next->next = new Node(30) ;
    list1.head->next->next->next = new Node(40) ; 

    
    list2.head = new Node(1) ;
    list2.head->next = list1.head->next->next  ; // 30 is the merge point 

    cout << "Merging point is : " << findMergePoint(list1.head , list2.head ) << endl ; 

    return 0 ; 
}












