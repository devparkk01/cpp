#include<iostream>
#define endl '\n'

using namespace std ; 

class Node {
    public: 
    int data ;
    Node* next ;
    
    Node (int item ) {
        data = item ; 
        next = nullptr ;
    }
};

class LinkedList {
    public:
    Node* head ; 

    LinkedList() {
        head = nullptr ; 
    }
};

Node * createList ( Node * head , int * arr , int size ) {
    head = new Node(arr[0]) ; 
    Node * curr = head ; 
    for (int i = 1 ; i < size  ; ++i ) {
        curr->next = new Node(arr[i])  ; 
        curr = curr->next ; 
    }
    return head ; 
}

void print(Node * head ) {
    Node * curr = head; 
    while (curr != nullptr ) {
        cout << curr->data  << " " ;
        curr = curr->next ; 
    } 
    cout<< endl; 
}

int main () {
    LinkedList list = LinkedList() ; 
    int arr[] = {4,6,7,9,36,4,22,40} ;
    list.head = createList(list.head ,arr , sizeof(arr)/sizeof(arr[0]) ) ; 
    print(list.head ) ;

    return 0 ; 
}