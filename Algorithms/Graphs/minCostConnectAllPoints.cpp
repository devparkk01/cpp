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
 /////// --------------------- /////////

// Using kruskals algo
/*

time: sorting will be O(e log e) where e represents total no of edges whie is n*n.
rest is kruskals. iterating through edgeList and for each edge we are uniting two points. taking union takes O(log e) time.

Kruskals time: O(e log e)

overall time: O( e log e) + O(e log e) where e = n *n 

*/
#define edge pair<int, pair<int, int>>
class Solution {
    vector<int>parent;
    vector<int>size; 

public:
    int find(int u) {
        if ( parent[u] != -1) {
            return parent[u] = find(parent[u]);
        }
        return u;
    }
    bool unite(int u, int v) {
        int up = find(u);
        int vp = find(v);
        if ( up == vp) {
            return false; 
        }

        if (size[up] > size[vp]) {
            parent[vp] = up ; 
            size[up] += size[vp];
        }
        else {
            parent[up] = vp;
            size[vp] += size[up];
        }
        return true; 
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        // create edgeList
        vector<edge>edgeList(n); 
        parent.resize(n, -1); size.resize(n);

        int ans = 0 ; 

        for(int i = 0 ;  i < n ; ++i) {
            for(int j = i + 1 ; j < n ; ++j) {
                int dist = abs(points[i][1] - points[j][1]) + abs(points[i][0]- points[j][0]);
                edgeList.push_back({dist, {i, j }});
            }
        }

        sort(edgeList.begin(), edgeList.end());

        int edgesCount = 0;
        for(int i = 0 ; i < edgeList.size(); ++i) {
            auto temp = edgeList[i];
            auto price = temp.first; 
            auto u = temp.second.first; 
            auto v = temp.second.second; 

            if ( unite(u, v)) {
                ans += price; 
                edgesCount++; 
            }
            if ( edgesCount == n -1) {
                break; 
            }
        }
        return ans; 
    }
};