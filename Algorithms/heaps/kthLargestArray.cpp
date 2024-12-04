/*
https://leetcode.com/problems/kth-largest-element-in-an-array/
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int , vector<int> , greater<int> > pq  ;
        for (int &x : nums ) {
            if (pq.size() < k ) {
                pq.push(x) ;
            }
            else {
                if (x > pq.top() ) {
                    pq.pop() ;
                    pq.push(x) ;
                }
            }
        }
        return pq.top() ;
    }
};