/*
https://leetcode.com/problems/merge-k-sorted-lists/description/

of course original lists will get distorted .
time : O(n log k)
where, n is total no of nodes , and k is no of sorted lists
space : O(k)
*/


// for min heap
class Compare {
    public:
    bool operator() (ListNode *a, ListNode *b) {
        return a->val > b->val; 
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size(); 
        ListNode *res = NULL, *curr = res; 
        ListNode *temp ;
        if ( k == 0) return res; 

        priority_queue<ListNode*, vector<ListNode *>, Compare > minHeap; 
        for(int i = 0 ; i < k ; ++i) {
            if ( lists[i]) {
                minHeap.push(lists[i]);
            }
        }

        while(!minHeap.empty()) {
            temp = minHeap.top() ; minHeap.pop(); 
            // didn't find the head of the merged linked list yet.
            if ( res == NULL) {
                res = temp ; 
                curr = temp ; 
            }
            // already found the head of the merged linked list. 
            else {
                curr->next=temp ; 
                curr = curr->next; 
            }
            // push the next element of this list to the minHeap
            if ( temp->next ) {
                minHeap.push(temp->next);
            }
        }

        return res; 

    }
};