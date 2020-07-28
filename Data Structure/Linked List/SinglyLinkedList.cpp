#include<iostream>
#include<stack>
#define endl '\n' ;  // macro for breaking new line  
using namespace std ; 

class Node {
    public :
    int data ; 
    Node * next ; 

    Node (int data) {
        this->data = data ; 
        next = NULL; 
    }

} ; 

class LinkedList {
    public : 
    Node * head ; 
    int count ; 
    LinkedList () {
        head = NULL ; 
        count = 0 ; 
    }

    void append (int item ) {
        Node * newNode = new Node(item) ; 
        if (head == NULL) {
            head = newNode ; 
        }
        else {
            Node * currNode = head ; 
            while (currNode->next != NULL) {
                currNode = currNode->next ; 
            }
            currNode->next = newNode ; 
        }
        count++ ; 
    }

    void display() {
        Node * currNode = head ; 
        while (currNode != NULL) {
            cout << currNode->data << " " ;
            currNode = currNode->next ; 
        }
        cout << endl ; 

    }
    int size () {
        return count ; 
    }
    void prepend(int item) ; 
    void reverse() ; 
    void reversePrint() ;            // using stack  data structure 
    void deleteBeg() ; 
    void deleteEnd() ; 
    
} ; 

void LinkedList :: prepend(int item) {
    Node * newNode = new Node(item ) ; 
    newNode->next = head ; 
    head = newNode ; 
    count++ ; 
}

void LinkedList :: reverse() {
    Node * prevNode = NULL ; 
    Node * currNode = head ; 
    Node * nextNode = NULL ; 
    while (currNode!= NULL) {
        nextNode = currNode->next ; 
        currNode->next = prevNode ; 
        prevNode = currNode ; 
        currNode = nextNode ; 
    }
    head = prevNode ; 
}

void LinkedList :: reversePrint() {
    stack<int > reversed ; 
    Node* currNode = head ; 
    while (currNode != NULL) {
        reversed.push(currNode->data) ; 
        currNode = currNode->next ; 
    }

    while(! reversed.empty()) {
        cout << reversed.top()  << " " ; 
        reversed.pop() ; 
    }
    cout << endl ; 
}

void LinkedList :: deleteBeg () {
    if ( head != NULL ) {
        Node * curr = head ; 
        head = head->next ;
        delete curr ; 
        count-- ; 
    }
}

void LinkedList:: deleteEnd() {
    if (head == NULL ) 
        return ; 
    else if ( head->next == NULL ) {
        delete head ; 
        head = NULL ; 
    }
    else {
        Node * curr = head , *prev = NULL ; 
        while (curr->next != NULL) {
            prev = curr ; 
            curr = curr->next ; 
        }
        prev->next = NULL ; 
    }
    count-- ; 
}

//  using recursion to print revese 
void reversePrint (Node * head ) {      
    if ( head != NULL) {
        reversePrint(head->next ) ;
        cout << head->data << " " ; 
    }
}

int main () {
    LinkedList items = LinkedList() ; 
    items.append(19) ; 
    items.append(34) ;
    items.append(98) ; 
    items.display() ;
    items.prepend(9) ;
    items.display() ; 
    cout << "Size " << items.size() << endl ; 
    items.reverse() ;
    items.display() ; 
    // items.reversePrint() ; 
    reversePrint( items.head ) ;  
    cout << endl ; 
    items.deleteBeg() ; 
    items.display() ;
    cout << "Size " << items.size()<< endl ; 
    items.deleteEnd() ;
    items.display() ;
    cout << "Size "<< items.size() << endl ; 
    return 0 ;

}





