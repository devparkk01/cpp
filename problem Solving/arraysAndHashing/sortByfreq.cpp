/*Given an array A[] of integers, sort the array according to frequency of elements.
That is elements that have higher frequency come first. If frequencies of two elements are same,
 then smaller number comes first.

*/

#include <bits/stdc++.h>
using namespace std;

bool compare( pair<int , int >&a , pair<int, int>&b) {
	if (a.second == b.second)
		return a.first < b.first ;
	return a.second > b.second  ;
}


int main() {
	//code
	int t ; cin >> t;
	while (t-- ) {
		int n ; cin >> n; int A[n] ;
		for (int i = 0 ; i < n; ++i ) cin >> A[i] ;
		unordered_map<int , int > um ;
		for (int i = 0 ; i < n ; ++i ) {
			um[A[i]]++ ;
		}
		vector<pair<int , int> > v;
		for (auto it = um.begin() ; it != um.end() ; ++it ) {
			v.push_back({it->first , it->second }) ;
		}
		sort(v.begin(), v.end(), compare ) ;
		for (auto it : v ) {
			for (int i = 0 ; i < it.second ; ++i ) {
				cout << it.first << " " ;
			}
		}
		cout << endl ;

	}
	return 0;
}