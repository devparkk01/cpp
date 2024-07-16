/*
https://leetcode.com/problems/minimum-height-trees/

AWESOME problem. Look into leetcode editorial ( if available ) for explanation. 
else, I have also added the explanation with diagrams into the notebook DSA 3. 
Do try this problem.

We will use topo sort here. 

*/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n); 
        vector<int>degree(n);
        vector<int>ans; 

        // edge cases
        if ( n == 1) return {0};
        if ( n == 2) return {0, 1};

        // build the graph
        for(auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }

        queue<int>q; 
        // push all the leaf nodes ( nodes having degree 1) to the queue
        for(int i = 0 ; i < n; ++i) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int size = q.size();
            // clear the vector
            ans.clear();
            for(int i = 0 ; i < size; ++i) {
                int u = q.front(); q.pop(); 
                ans.push_back(u);
                degree[u]--;

                for(auto &v: graph[u]) {
                    // graph[v].erase(u);
                    degree[v]--;
                    if (degree[v] == 1) {
                        q.push(v);
                    }
                }
            }


        }
        return ans; 
    }
};