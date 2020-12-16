/*
https://leetcode.com/problems/non-overlapping-intervals/

Approach :
Sort all the intervals based on their endtime in increasing order .
Pick the interval one by one , if any interval overlaps then we need to delete this interval,
i.e , If starttime of this interval is less than the endtime of the last interval then delete
this interval . else this won't create an overlapping interval . so we will keep this interval
and update endtime to be equal to endtime of this interval .
*/

class Solution {
public:
	static bool compare(vector<int>&a , vector<int>&b) {
		return a[1] < b[1] ;
	}
	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		int n = intervals.size() ;
		if ( n == 0 || n == 1  ) return 0 ;
		sort(intervals.begin() , intervals.end() , compare)  ;
		int count = 0 ;
		int endTime = intervals[0][1] ;
		for (int i = 1 ; i < n ; ++i ) {
			if (intervals[i][0] < endTime ) count++ ;
			else endTime = intervals[i][1] ;
		}
		return count ;
	}
};


