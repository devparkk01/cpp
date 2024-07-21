/*
https://leetcode.com/problems/min-cost-to-connect-all-points/description/

interesting problem.
Based on finding minimum spanning tree of the given graph. .

Both kruskals and prims can be used here.

Prims: O(n^2 log n)


*/
#include<bits/stdc++.h>
using namespace std; 


#define ip pair<int, int>

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool>mstSet(n);
        vector<int>keys(n , INT_MAX);
        // minHeap which gives us minimum key value at the top
        // pair< int, int> => dist, index of the node
        priority_queue<ip, vector<ip>, greater<ip>> minHeap; 

        // mark first node's distance as 0 
        keys[0] = 0 ;
        // push first node into the minHeap
        minHeap.push({keys[0],  0});
        int edgesIncluded = 0 ;
        while(edgesIncluded < n - 1) {
            auto [dist, node] = minHeap.top(); minHeap.pop(); 

            // if the popped node has already been included in the mstSet, then do nothing
            if ( mstSet[node]) continue; 
            // else include it in the mstSet
            mstSet[node] = 1; 

            edgesIncluded++; 
            int x = points[node][0];
            int y = points[node][1];

            for(int i = 0 ; i < n ; ++i) {
                if ( i == node) continue; 
                int adjx  = points[i][0];
                int adjy  = points[i][1];
                int adjDist = abs(adjx- x) + abs(adjy - y);
                if (mstSet[i] == false && keys[i] > adjDist) {
                    keys[i] = adjDist; 
                    minHeap.push({keys[i], i });
                }
            }
        }

        return accumulate(keys.begin(), keys.end(), 0 ); 
    }
};