/*
https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

of course original lists will get distorted .
time : O(n log k)
where, n is total no of nodes , and k is no of sorted lists
space : O(k)
*/


// for min heap
class compare {
public:
    bool operator()(Node*  &a , Node* &b) {
        return a->data > b->data ;
    }
};

class Solution {
public:

    Node * mergeKLists(Node *arr[], int K)
    {
        Node *head = NULL ;
        Node * curr = head  ;
        priority_queue<Node * , vector<Node*> , compare > pq ; // using min heap

        for (int i = 0 ; i < K ; ++i ) {
            if (arr[i])pq.push(arr[i]) ;
        }
        Node *top  ;

        while (!pq.empty()) {
            top = pq.top() ;
            pq.pop() ;
            if (head == NULL ) {
                head = top ;
                curr = top ;
            }
            else {
                curr->next = top ;
                curr = curr->next ;
            }
            if (top->next ) pq.push(top->next ) ;
        }
        return head;

    }
};

