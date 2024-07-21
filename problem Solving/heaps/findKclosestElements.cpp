/*
https://leetcode.com/problems/find-k-closest-elements/description/


time: O(n log k)
*/


class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // ans vector 
        vector<int>ans; ans.reserve(k);
        // create a max heap. Stores a pair. 
        //first element of the pair is absolute difference with the input x, and the second element is its index.
        priority_queue<pair<int, int >> maxHeap; 

        // push first K element of the array to the maxHeap
        for(int i = 0 ; i < k ; ++i) {
            maxHeap.push({abs(arr[i] - x), arr[i]});
        }
        // Process next ( n - k ) elements
        for(int i = k ; i < arr.size() ; ++i) {
            auto [diff, elem] = maxHeap.top(); 
            // if abs difference between this element and x is smaller than the top of the maxHeap, 
            // then remove the element at the top of the stack and push the current element. 
            if ( abs(arr[i] - x) < diff) {
                maxHeap.pop(); 
                maxHeap.push({abs(arr[i] - x), arr[i]});
            }
        }
        // Push all items in the maxHeap to the ans vector. 
        while(!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second); maxHeap.pop(); 
        }
        sort(ans.begin(), ans.end());
        return ans; 
    }
};