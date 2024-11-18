/*
https://leetcode.com/problems/largest-component-size-by-common-factor/

*/



class Solution {
public:
    vector<int>parent, size; 

    int findParent(int u) {
        if ( parent[u] == u) {
            return u; 
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v) {
        int parU = findParent(u);
        int parV = findParent(v);
        if ( parU == parV) {
            return ; 
        }
        if ( size[parU] < size[parV]) {
            parent[parU] = parV; 
            size[parV] += size[parU];
        } else {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size(); 
        int maxElem = *max_element(nums.begin(), nums.end());
        parent.resize(maxElem + 1);
        size.resize(maxElem + 1, 1);
        for(int i = 1 ; i <= maxElem; ++i) {
            parent[i] = i; 
        }

        for(int &num : nums) {
            for(int fact = 2; fact < floor(sqrt(num)) + 1; ++fact) {
                if ( num % fact == 0) {
                    unionBySize(fact, num);
                    unionBySize(num, num/ fact);
                }
            }
        }

        unordered_map<int, int> componentCount; 
        int ans = 1; 
        for(int &node : nums) {
            componentCount[findParent(node)]++;
            ans = max(ans, componentCount[findParent(node)]);
        }
        return ans; 
        
    }
};