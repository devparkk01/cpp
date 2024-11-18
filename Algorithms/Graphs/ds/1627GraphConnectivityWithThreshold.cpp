/*
https://leetcode.com/problems/graph-connectivity-with-threshold/description
*/

#include<bits/stdc++.h>

class Solution {
public:
    vector<int>component, size; 

    int findComponent(int u ) {
        if ( component[u] == u) {
            return u;
        }
        return component[u] = findComponent(component[u]);
    }

    void connect(int u, int v) {
        int compU = findComponent(u);
        int compV = findComponent(v);

        if ( compU == compV) {
            return ; 
        }
        if ( size[compU] < size[compV]) {
            component[compU] = compV; 
            size[compV] += size[compU];
        } else {
            component[compV] = compU; 
            size[compU] += size[compV];
        }
    }

    bool connected(int u, int v) {
        return findComponent(u) == findComponent(v);
    }

    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        size.resize(n + 1, 1);
        component.resize(n + 1);
        for(int i = 1; i <= n ; ++i) {
            component[i] = i ; 
        }
        // connect the nodes
        for(int t= threshold + 1; t <= n ; ++t) {
            int multiple = 2; 
            while(t * multiple <= n) {
                connect(t, t*multiple);
                multiple++;
            }
        }
 
        vector<bool>ans(queries.size());
        for(int i = 0 ; i < queries.size() ; ++i) {
            ans[i] = connected(queries[i][0], queries[i][1]);
        }
        return ans; 
    }
};