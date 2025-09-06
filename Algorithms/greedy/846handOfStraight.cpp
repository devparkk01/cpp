/*
https://leetcode.com/problems/hand-of-straights/

*/

//  time: O(n log n + n * k ), n is the size of hand, k is groupSize
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> count; 
        for(auto &x : hand) {
            count[x]++; 
        }


        while(!count.empty()) {
            auto startHand = count.begin()->first; 

            for(int i = 0 ; i < groupSize ; ++i) {
                // check startHand + i exists
                if (count.find(startHand + i) != count.end()) {
                    count[startHand + i]--;
                    if ( count[startHand + i] == 0) {
                        count.erase(startHand + i);
                    } 
                } else {
                    return false; 
                }
            }
        }
        return true; 
    }
};

/*
1 2 2 3 3 4 6 7 8 
1 :1 0 
2 : 2 1 
3 : 2 1 
4 : 1
6: 1 
7: 1 
8: 1 



*/

class Compare {
    public:
    bool operator() (ListNode*a, ListNode*b) {
        return a->val > b->val; 
    }
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode * merged = nullptr; 
        ListNode * curr = nullptr; 
        int k = lists.size(); 
        priority_queue< ListNode*, vector<ListNode*> , Compare> pq; 
        // push first node of each list into the pq 
        for(int i = 0 ; i < k ; ++i) {
            pq.push(lists[i]);
        }

        // process first element, and set the curr
        ListNode *temp = pq.top() ; pq.pop(); 
        merged = temp; 
        curr = merged; 
        pq.push(temp->next);


        while(!pq.empty()) {
            temp = pq.top(); pq.pop(); 
            curr->next = temp; 
            curr = curr->next; 
            if( temp->next) {
                pq.push(temp->next);
            }
        }
        return merged; 
    }
}
