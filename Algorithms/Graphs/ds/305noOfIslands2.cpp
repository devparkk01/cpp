/*
https://leetcode.com/problems/number-of-islands-ii/

it's an interesting problem. 

You are given an empty 2D binary grid grid of size m x n. The grid represents a map where 0's represent water 
and 1's represent land. Initially, all the cells of grid are water cells (i.e., all the cells are 0's).

We may perform an add land operation which turns the water at position into a land. 
You are given an array positions where positions[i] = [ri, ci] is the position (ri, ci) 
at which we should operate the ith operation.

Return an array of integers answer where answer[i] is the number of islands after turning the 
cell (ri, ci) into a land.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.



Brute force approach is running dfs after each position.
Optimized approach is based on DSU



*/



class Dsu{
    vector<int>parent;
    vector<int>rank; 
    int count = 0 ; 

    public: 
    Dsu(int size) {
        parent.resize(size, -1);
        rank.resize(size, 0);
    }

    void setLand(int cellIndex) {
        if ( !isLand(cellIndex)) {
            parent[cellIndex] = cellIndex; 
            count++; 
        }
    }

    bool isLand(int cellIndex) {
        return (parent[cellIndex] != -1); 
    }

    int countIsland() {
        return count; 
    }

    int find(int cellIndex) {
        if ( parent[cellIndex] != cellIndex) {
            parent[cellIndex] = find(parent[cellIndex]);
        }
        return parent[cellIndex];
    }

    void groupIsland(int cellIndex, int adjCellIndex) {
        int firstParent = find(cellIndex);
        int secondParent = find(adjCellIndex);

        if ( firstParent == secondParent) {
            return ; 
        }

        if ( rank[firstParent] < rank[secondParent]) {
            parent[firstParent] = secondParent;
        } else if ( rank[firstParent] > rank[secondParent]) {
            parent[secondParent] = firstParent;
        } else {
            parent[secondParent] = firstParent;
            rank[firstParent]++; 
        }
        count--; 
    }


};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        auto ds = Dsu(m * n);

        int dx[] = {-1 , 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<int>ans; ans.reserve(positions.size()); 

        for(auto &position: positions) {
            int x = position[0];
            int y = position[1];

            int cellNo = x * n + y ; 

            ds.setLand(cellNo);

            for(int i = 0 ; i < 4; ++i) {
                int adjX = x + dx[i];
                int adjY = y + dy[i];
                int adjCellNo = adjX * n + adjY; 

                if ( adjX >= 0 && adjX <m && adjY >= 0 && adjY < n && ds.isLand(adjCellNo)) {
                    ds.groupIsland(cellNo, adjCellNo);
                }

            }
            ans.push_back(ds.countIsland());

            
        }
        return ans; 



    }
};