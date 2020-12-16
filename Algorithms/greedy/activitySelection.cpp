/*You are given n activities with their start and finish times. Select the maximum number of activities
 that can be performed , assuming that a person can only work on a single activity at a time.

time : O(nlog n)
*/


#include<bits/stdc++.h>
using namespace std ;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define endl '\n'
#define ll long long
#define f(i , k , n ) for(int i = k ; i < n ; ++i)
#define ip pair<int , int >
#define um unordered_map<int , int >
#define us unordered_set<int >
#define vec vector

bool compare(ip&a , ip&b ) {
	return a.second < b.second ;
}

int maxActivites(vec<ip>&activities , int n ) {
	sort(activities.begin() , activities.end() , compare) ;
	int count = 0 ;
	int i = 0;
	int endTime = -1 ;
	while (i < n ) {
		if ( activities[i].first >= endTime) {
			count++ ;
			endTime = activities[i].second ;
		}
		i++ ;
	}
	return count ;
}




signed main () {
	vec<ip>activities =  {{10 , 20} , {12 , 25} , {20, 30}} ;
	int n = activities.size() ;

	cout << maxActivites(activities , n ) ;

	return 0 ;

}