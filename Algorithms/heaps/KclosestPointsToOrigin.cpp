/*https://leetcode.com/problems/k-closest-points-to-origin/description/


Approach 1: use custom sorting, time: O(n log n)

Approach 2: use maxHeap, time: O(n log k)
*/


// Approach 2
#define ip pair<int, int>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        // keep a maxHeap, stores pair< dist, index> 
        priority_queue<ip> maxHeap; 
        vector<vector<int>>ans; ans.reserve(k);

        // process first k elements first and push them into maxHeap
        for(int i = 0 ; i < k ; ++i) {
            int dist = (points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            maxHeap.push({dist, i});
        }
        
        // process next (n - k) elements
        for(int i = k ; i < n ; ++i) {
            int dist = (points[i][0] * points[i][0] + points[i][1] * points[i][1]);
            // if dist is less than the distance what we have at the top of the maxHeap
            if ( dist < maxHeap.top().first ) {
                maxHeap.pop(); 
                maxHeap.push({dist, i});
            }
        }
        while(!maxHeap.empty()) {
            auto [dist, i] = maxHeap.top(); maxHeap.pop();
            ans.push_back(points[i]);
        }
        return ans; 

    }
};