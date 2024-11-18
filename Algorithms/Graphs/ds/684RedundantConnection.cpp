/*
https://leetcode.com/problems/redundant-connection/

*/

class Solution {
public:
    vector<int>parent, size; 

    int findParent(int u) {
        if( parent[u] == u) {
            return u; 
        }
        return parent[u] = findParent(parent[u]);
    }

    bool unionBySize(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        if (parU == parV) {
            return  false; 
        }
        if (size[parU] < size[parV]) {
            parent[parU] = parV;
            size[parV] += size[parU];
        } else{
            parent[parV] = parU;
            size[parU] += size[parV];
        }
        return true; 
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1); size.resize(n + 1, 1);
        for(int i = 1 ; i <= n ; ++i) {
            parent[i] = i; 
        }

        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            
            if (!unionBySize(u, v)){
                return edge; 
            }
        }
        return {};
    }

};