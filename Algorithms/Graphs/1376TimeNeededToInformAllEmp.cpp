/*
https://leetcode.com/problems/time-needed-to-inform-all-employees/description/

we can employ both BFS and DFS approach 
*/
class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // int maxTime = INT_MIN; 
        vector<vector<int>>relations(n);
        for(int i = 0 ; i < n ; ++i) {
            if ( i == headID) {
                continue;
            }
            relations[manager[i]].push_back(i);
        }

        auto maxTime = dfs(n , headID, relations, informTime);
        return maxTime;

    }
    int dfs(int n, int headId, vector<vector<int>>&relations, vector<int>&informTime) {

        int maxTime = 0 ; 
        for(auto &emp: relations[headId]) {
            maxTime = max(maxTime, dfs(n, emp, relations, informTime));
        }
        maxTime += informTime[headId];
        return maxTime; 
    }
};