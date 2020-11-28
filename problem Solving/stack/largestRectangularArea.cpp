/*Find the largest rectangular area possible in a given histogram where the largest
rectangle can be made of a number of contiguous bars. For simplicity, assume that
all bars have same width and the width is 1 unit.

*/

#include<bits/stdc++.h>
using namespace std ;
#define f(i ,k , n ) for(int i = k ; i < n ; ++i)


/* Naive solution :


*/

/* Stack solution */

int maxRectArea(vector<int>&a ) {
	int n = a.size() ;
	int maxArea = 0 ;
	int curArea  ;
	stack<int>s ;
	f(i , 0 , n ) {
		if ( s.empty() ) {
			s.push(i) ;
			curArea = a[i] * (i + 1 ) ;
			maxArea = max(maxArea , curArea) ;
		}
		else if ( a[i] > a[s.top()]) {
			s.push(i) ;
		}
		else {
			while (!s.empty() && a[i] <= a[s.top()])
				s.pop() ;
			if (s.empty()) curArea = a[i] * (i + 1 ) ;
			else curArea = a[i] * ( i - s.top()) ;

			s.push(i) ;

			maxArea = max(maxArea , curArea) ;
		}
	}
	if ( !s.empty()) {
		int last = s.top() ;
		while (!s.empty()) {
			curArea = a[s.top()] * (last - s.top() + 1 ) ;
			maxArea = max(maxArea , curArea) ;
			s.pop() ;
		}
	}

	return maxArea ;

}





signed main () {
	vector<int>a = {6, 2, 5, 4, 5, 1, 6} ;

	cout << maxRectArea(a) << endl ;

	return 0 ;
}