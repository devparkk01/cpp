/*

https://leetcode.com/problems/satisfiability-of-equality-equations/description/
*/


class Solution {
public:
    vector<int>parent;
    vector<int>size;

    int findParent(int u) {
        if (u == parent[u]) {
            return u; 
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u, int v){
        // get the ultimate parent of u
        auto ulp_u = findParent(u);
        // get the ultimate parent of v
        auto ulp_v = findParent(v);
        // if both the parents are same, they belong to the same set/components, we don't need to perform any union.
        if (ulp_u == ulp_v) {
            return ;
        }
        // if size of ulp_u is less than ulp_v, then attach ulp_u under ulp_v
        if ( size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            // attach ulp_v under ulp_u
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i = 0 ; i < 26; ++i) {
            parent[i] = i ; 
        }
        size.resize(26, 1);

        for(auto &equation: equations) {
            char op = equation[1];
            if( op == '=') {
                char first = equation[0];
                char second = equation[3];
                char firstParent = findParent(first - 'a');
                char secondParent = findParent(second - 'a');
                unionBySize(firstParent, secondParent);
            }
        }

        for(auto &equation: equations) {
            char op = equation[1];
            if ( op == '!') {
                char first = equation[0];
                char second = equation[3];
                char firstParent = findParent(first - 'a');
                char secondParent = findParent(second - 'a');
                if ( firstParent == secondParent) return false;
            }
        }

        return true; 
        
    }
};