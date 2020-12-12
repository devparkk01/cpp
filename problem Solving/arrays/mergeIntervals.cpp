/*Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals,
and return an array of the non-overlapping intervals that cover all the intervals in the input.

time : O(nlogn )
*/

#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'


void print(vector<vector<int>>&intervals) {
	for (auto &x : intervals) {
		cout << x[0] << " "  << x[1] << endl;
	}

}


vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size() ;
	vector<vector<int>>res ; res.reserve(n ) ;
	if ( n == 0 ) return res ;
	sort(intervals.begin() , intervals.end() ) ;

	vector<int>last = {intervals[0][0] , intervals[0][1]};


	for (int i = 1 ; i < n ; ++i ) {
		if ( intervals[i][0] <= last[1]) { // overlapping case , so merge them
			last[1] = max(last[1] , intervals[i][1]) ;
		}
		else {
			res.push_back(last ) ;
			last = intervals[i] ;
		}
	}
	res.push_back(last) ;
	return res  ;

}

signed main () {
	vector<vector<int>>intervals = { {1 , 3} , {2 , 6 } , {8 , 10 } , { 15 , 18}} ;
	vector<vector<int>>mergedInteval = merge(intervals) ;
	print(mergedInteval) ;

	return 0  ;

}