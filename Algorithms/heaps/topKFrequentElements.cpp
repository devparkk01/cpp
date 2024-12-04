/*
https://leetcode.com/problems/top-k-frequent-elements/description/

Given an integer array nums and an integer k, return the k most frequent elements.
 You may return the answer in any order.

 time: O(n log k)

*/


#define ip pair<int, int>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans; ans.reserve(k);

        priority_queue<ip, vector<ip>, greater<ip>>minHeap; 
        // stores the frequency of each element
        unordered_map<int, int>counts;

        for(int &x: nums) {
            counts[x]++;
        }
        // counter to keep track of first k elements
        int i = 0 ; 
        for(auto &it: counts) {
            if ( i < k ) {
                minHeap.push({it.second, it.first});
                i++;
            } else {
                auto [freq, elem] = minHeap.top(); 
                if( freq < it.second) {
                    minHeap.pop();
                    minHeap.push({it.second, it.first});
                }
            }
        }

        while(!minHeap.empty()) {
            auto [freq, elem] = minHeap.top();  minHeap.pop();
            ans.push_back(elem);
        }

        return ans; 
    }
};