/*
https://leetcode.com/problems/insert-interval/description/



*/


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if ( n ==0 ) return { newInterval}; 

        vector<vector<int>>res; res.reserve(n + 1);
        
        // get to the interval with which new interval has overlapping 
        int i = 0 ;
        while( i < n && intervals[i][1] < newInterval[0]){
            res.push_back(intervals[i]);
            i++; 
        }
        // ith element may some conflict with the newInterval
        // that's why you need to merge these intervals 
        while( i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++; 
        }

        res.push_back(newInterval);
        while( i < n) {
            res.push_back(intervals[i]);
            i++; 
        }
        return res; 
    }
};