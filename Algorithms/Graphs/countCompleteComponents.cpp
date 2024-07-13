/*
https://leetcode.com/problems/count-the-number-of-complete-components/

Approach: Do simple dfs
time: O(v + E) 
*/

#include<bits/stdc++.h>
using namespace std; 

class Solution {
public:

    void dfs(int u, vector<vector<int>>&graph, vector<bool>&visited, int &nodes, int &edges) {
        visited[u] = 1; 
        // increase the nodes count
        nodes++; 
        // increase the edges count.
        edges += graph[u].size(); 

        for(int &v: graph[u]) {
            if ( !visited[v]) {
                dfs(v, graph, visited, nodes, edges);
            }
        }
    }


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // build the adjacency list
        vector<vector<int>>graph(n);
        for(auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        // keeps track of nodes that are already visited.
        vector<bool>visited(n);
        // Count of components which are complete
        int completeCount = 0;
        for(int u  =0 ; u < n ; ++u) {
            if ( !visited[u]) {
                // nodes is used to keep track of total nodes in a particular component.
                // edges is used to keep track of total edges in a particular component.
                int nodes = 0 , edges = 0 ;
                dfs(u, graph, visited, nodes, edges);
                // if total no edges in the component is equal to n*(n-1) then it's a complete component.
                if (edges == nodes * (nodes - 1)) {
                    completeCount++;
                }
            }
        }
        return completeCount; 
    }
};