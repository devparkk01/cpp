/*
https://leetcode.com/problems/pacific-atlantic-water-flow/description/


both bfs and dfs can be used here. 
*/

// bfs approach 

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool isSafe(int x, int y, int m , int n) {
        if ( x < 0 || x >= m || y < 0 || y >= n ) return false; 
        return true; 
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(); 
        int n = heights[0].size();

        queue<pair<int, int>> pacificQ; 
        queue<pair<int, int>> atlanticQ; 

        // boolean matrix to represent cells which can flow to pacific ocean
        vector<vector<bool>> pacificReachable(m, vector<bool>(n)); 
        // boolean matrix to represent cells which can flow to atlantic ocean
        vector<vector<bool>> atlanticReachable(m, vector<bool>(n)); 


        for(int j= 0 ; j < n ; ++j) {
            // All cells of first row can flow to pacific
            pacificQ.push({0, j});
            pacificReachable[0][j] = true; 
            // All cells of last row can flow to atlantic
            atlanticQ.push({m - 1, j});
            atlanticReachable[m-1][j] = true; 
        }

        for(int i= 0 ; i < m ; ++i) {
            // All cells of first column can flow to pacific
            pacificQ.push({i, 0});
            pacificReachable[i][0] = true; 
            // All cells of last column can flow to atlantic
            atlanticQ.push({i, n -1});
            atlanticReachable[i][n - 1] = true;
        }

        // run bfs on both
        bfs(heights, m , n, pacificQ, pacificReachable);
        bfs(heights, m, n, atlanticQ, atlanticReachable);

        vector<vector<int>>ans; 

        // add those cells into ans which can flow to both pacific and atlantic 
        for(int i=0 ; i < m ; ++i) {
            for(int j = 0 ; j < n ; ++j) {
                if (pacificReachable[i][j] && atlanticReachable[i][j]) {
                    ans.push_back({i , j});
                }
            }
        }

        return ans; 
    }
    
    vector<vector<bool>> bfs(vector<vector<int>>&heights, int m, int n, queue<pair<int, int>>&q, vector<vector<bool>>&reachable) {

        while(!q.empty()) {
            auto [x, y] = q.front(); q.pop(); 
            // consider all neighbour 4 cells 
            for(int i = 0 ; i < 4 ; ++i) {
                int adjx = x + dx[i];
                int adjy = y + dy[i];

                // adjacent cell is safe(within the boundary), has not been reachable 
                // and height of adjacent cell is more or equal to the height of the current cell  
                if (isSafe(adjx, adjy, m, n) && reachable[adjx][adjy] == false && heights[adjx][adjy] >= heights[x][y]) {
                    q.push({adjx, adjy});
                    reachable[adjx][adjy] = true;
                }
            }

        }
        return reachable;
    }
};