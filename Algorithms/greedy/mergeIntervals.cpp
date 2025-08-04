/*
https://leetcode.com/problems/merge-intervals/description/

*/

class Solution {
public:
    bool static compare(vector<int>&a, vector<int>&b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size(); 
        if ( n == 1) return intervals; 

        vector<vector<int>>result; 
        sort(intervals.begin(), intervals.end(), compare); 


        auto lastInterval = intervals[0];

        for(int i = 1 ; i < n ; ++i) {
            // overlapping 
            if ( lastInterval[1] >= intervals[i][0] ) {
                lastInterval[1] = max(lastInterval[1], intervals[i][1]);
            } else {
                result.push_back(lastInterval);
                lastInterval = intervals[i];
            }
        }

        result.push_back(lastInterval);

        return result; 


    }
};