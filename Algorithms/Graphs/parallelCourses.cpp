/*

https://leetcode.com/problems/parallel-courses/description/
*/

#include<bits/stdc++.h>


class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        // build the graph 
        vector<vector<int>>graph(n + 1); 
        // stores indegree for each node (here course)
        vector<int>indegree(n + 1); 
        // indegree[0] = INT_MAX; 

        // build the graph 
        for(auto &relation: relations) {
            int u = relation[0], v = relation[1];
            graph[u].push_back(v);
            indegree[v]++;
        }

        int semCount = 0; 
        queue<int>q; 
        // not looping for i = 0, because there is no course 0 
        for(int i = 1; i <= n ; ++i) {
            if( indegree[i] == 0) {
                q.push(i);
            }
        }
        // simple KAHN'S algo for topo sort 
        while(!q.empty()) {
            int size = q.size(); 
            semCount++; 
            while(size--) {
                auto node = q.front(); q.pop();
                for(auto &adjNode: graph[node]) {
                    indegree[adjNode]--;
                    if(indegree[adjNode] == 0) {
                        q.push(adjNode);
                    }
                }
            }
        }
        // not looping for i = 0, because there is no course 0 
        for(int i = 1 ; i <= n ; ++i) {
            // if a course's indegree value is not 0, then it means that particular course 
            // has not been taken, hence return -1
            if ( indegree[i] != 0) return -1; 
        }
        return semCount; 

    }
};