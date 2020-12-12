/*Find the largest rectangular area possible in a given histogram where the largest
rectangle can be made of a number of contiguous bars. For simplicity, assume that
all bars have same width and the width is 1 unit.

*/

#include<bits/stdc++.h>
using namespace std ;
#define f(i ,k , n ) for(int i = k ; i < n ; ++i)
#define ll long long
#define endl '\n'


/* Naive solution :


*/

/* Stack solution */
int maxRectArea(vector<int>&a ) {
	int n = a.size() ;
	int maxArea = 0 ;
	int curArea  ;
	stack<int>s ;
	int hgt ;
	int i = 0 ;
	while ( i < n ) {
		if (s.empty() || a[s.top()] <= a[i]) {
			s.push(i) ; i++ ;
		}
		else {
			hgt = a[s.top()] ; s.pop() ;
			if ( s.empty() ) curArea = hgt * i ;
			else curArea = hgt * (i - 1 - s.top() ) ;
			maxArea = max(curArea , maxArea) ;
		}
	}
	while (!s.empty()) {
		hgt = a[s.top()] ; s.pop() ;
		if (s.empty() ) curArea = hgt * i ;
		else curArea = hgt * (i - 1 - s.top() ) ;
		maxArea = max(curArea , maxArea) ;
	}
	return maxArea ;

}





signed main () {
	vector<int>a = {6, 2, 5, 4, 5, 1, 6} ;

	cout << maxRectArea(a) << endl ;

	return 0 ;
}