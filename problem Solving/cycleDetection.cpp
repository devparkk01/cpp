/*
  A linked list is said to contain a cycle if any node is visited more than once while traversing the list.
      1 -> 2 -> 4 ->3-> 
           ↑_________ ↓    3 points back to 2 
         
     Hence . it contains a cycle , No node will point to None or NULL
    
     1 -> 2 -> NULL  
     Doesn't contain a cycle , will point to NULL 

*/

#include<iostream>
#define endl '\n'

using namespace std ;

class Node {
     public : 
     int data ; 
     Node* next ; 

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
} ; 


bool cycleDetection( Node * head ){
     Node * fast = head , * slow = head ;
     while ( fast!=nullptr && fast->next != nullptr) {
          slow = slow->next ;
          fast = fast->next->next ; 
          if (slow == fast ) {
               return true ; 
          }
     }
     return false ; 
}

/*
will make use of two pointers , fast and slow . slow traverse one node at a  time while second traverses two nodes at a time . 

*/


int main () {
     LinkedList list = LinkedList() ; 
     list.head = new Node(1) ; 
     list.head->next = new Node(2) ; 
     Node * curr = list.head->next ; 
     list.head->next->next = new Node(4) ; 
     list.head->next->next->next  = new Node(3) ; 

     cout << "Cycle contains : " << cycleDetection(list.head ) << endl ;

     list.head->next->next->next->next = list.head->next ; // making a cycle 

     cout << "Cycle contains : " << cycleDetection(list.head ) << endl ;

     return 0 ; 

}