/*
https://leetcode.com/problems/insert-interval/description/

*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto n = intervals.size(); 
        if ( n == 0 ) return {newInterval};
        vector<vector<int>> result;

        int i = 0 ; 
        // add all the intervals ending before newInterval starts, because they don't have any conflic with newInterval
        while( i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // merge all intervals that overlap with newInterval
        while(i < n && intervals[i][0] <= newInterval[1] ) {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }

        result.push_back(newInterval);

        while(i < n ) {
            result.push_back(intervals[i]);
            i++;
        }

        return result; 
 

    }
};