/*
Given a linked list , write a function to determine whether the list is a palindrome 

palindrome (1->2->1)  => true 

palindrome(2->3->1) => false 

*/


#include<iostream>
#include<stack>
#define endl '\n'

using namespace std ; 

class Node {
    public :
    int data ; 
    Node * next ; 

    Node (int item ) {
        data = item ; 
        next = nullptr ;  
    }
} ; 

class LinkedList {
    public:
    Node * head ; 

    LinkedList() {
        head = nullptr ; 
    }
} ; 

// one simple solution would be to reverse the linked list and then compare the nodes ,but that's not much efficient

// another solution would make use of stack data structure 
bool palindrome ( Node * head ) {
    Node * slow = head ; // moves by one node
    Node * fast = head ; // moves by two nodes 
    stack<int> stk ; // to store the first half of the linked list 

    while ( fast!= nullptr && fast->next != nullptr ) {
        stk.push(slow->data) ; 
        slow = slow->next ;
        fast = fast->next->next ; 
    }
    if ( fast != nullptr ) { // odd no of elements , 
            // don't put the condition fast->next == nullptr , cuz if fast is nullptr then it will behave unpredictably 
        slow = slow->next ; // ignore the middle element 
    }
    while (slow != nullptr ) {
        int elem = stk.top() ;
        stk.pop() ;
        if (elem != slow->data ) 
            return false ; 
        slow = slow->next ; 
    }

    return true ; 

}
    /*
    if fast == nullptr then the list is odd length , if fast->next == nullptr then list is even length
        1->2->3->2->1  
        slow = 1  , fast = 1 =>   stack [1] , slow = 2 , fast = 3 
        slow = 2 , fast = 3  => stack[1 , 2 ] , slow = 3 , fast = 1 
        fast->next == nullptr so it comes out of the while loop 
        but slow is at 3(which is the middle element ) , so we need to ignore this element and start checking 
        the next element for palindrome 
        1->2->3->3->2->1  
        slow = 1 , fast = 1 => stack[1] , slow = 2 , fast = 3
        slow = 2 , fast = 3 => stack[1 ,2 ] , slow = 3  , fast = 2 
        slow = 3 , fast = 2 => stack[1 , 2 , 3 ] , slow = 3  , fast = nullptr
        fast == nullptr , so it comes out of the while loop 
        slow is at 3 , which is the second middle element 
        Now , we can start checking from this element for the palindrome 

    */


Node * createList ( Node * head , int *arr , int size) {
    head = new Node(arr[0]) ; 
    Node * curr = head ; 
    for (int i = 1 ; i < size ; ++i ) {
        curr->next = new Node(arr[i])  ; 
        curr = curr->next ; 
    }
    return head ; 
}



int main () {
    int arr[] = {1 , 2 , 3 , 2 ,1 } ; 
    LinkedList list = LinkedList() ;
    list.head = createList(list.head , arr , sizeof(arr)/sizeof(arr[0]) ) ; 

    cout << "First list : " << palindrome(list.head ) << endl  ; 


    int arr2[]  = {1 , 2 , 3 , 3,  2 ,1 } ; 
    list.head = createList(list.head , arr2 , sizeof(arr2)/sizeof(arr2[0])) ; 

    cout << "Second list : " << palindrome(list.head ) << endl ; 

    int arr3[] = {2, 4, 6, 4, 1 } ;
    list.head = createList(list.head , arr3  , sizeof(arr3)/ sizeof(arr3[0])) ;  
    cout << "Third list : " << palindrome(list.head ) ;


    return 0 ; 

}
