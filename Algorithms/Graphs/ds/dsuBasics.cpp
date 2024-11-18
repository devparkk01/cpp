/*
Cover the basics of DSU (find using path compression and union by size). Union by rank is not covered here.
*/
#include<iostream>
#include<vector>

using namespace std; 

class DisjointSet{
    vector<int>size, parent; 
    public:
    DisjointSet(int n ) {
        // it can accomodate both 0 and 1 index based graph easily.
        size.resize(n+1, 1); // initially, the size of each node is 1.
        parent.resize(n+1);
        for(int i= 0 ; i <= n ; ++i ) {
            parent[i] = i ; // node is the parent of itself
        }
    }

    // recusively find the ultimate parent of a node, also do path compression so that a node points to it's ultimate parent 
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

};


int main() {
    DisjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    // if 3 and 7 belong to the same set or not 
    if ( ds.findParent(3) == ds.findParent(7)) {
        cout << "Belong to the same parent" << endl;  
    } else {
        cout << "Do not belong to the same parent " << endl;
    }

    ds.unionBySize(3, 7);

    if ( ds.findParent(3) == ds.findParent(7)) {
        cout << "Belong to the same parent" << endl;
    } else {
        cout << "Do not belong to the same parent " << endl;
    }

    return 0; 

}