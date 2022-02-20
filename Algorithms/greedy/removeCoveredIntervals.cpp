#include<bits/stdc++.h>
using namespace std ; 


bool compare(vector<int>&first , vector<int>&second) {
	return first[0] <= second[0];
}


int removeCoveredIntervals(vector<vector<int>>& intervals) {
	sort(intervals.begin() , intervals.end() , compare) ;

	int total_covers = 1  ;
	int covering_element_index = 0 ; 

	for(int i =1 ; i < intervals.size() ; ++i) {
		if(intervals[i][1] <= intervals[covering_element_index][1]) {
			continue; 
		}
		else {
			total_covers++; 
			covering_element_index = i ; 
		}
	}

	return total_covers  ; 

}

int main() {
	vector<vector<int>>intervals= {{1,4}, {2,3}};
	cout << removeCoveredIntervals(intervals) ;

	return 0 ; 
}