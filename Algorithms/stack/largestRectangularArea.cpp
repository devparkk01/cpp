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
A simple solution is to one by one consider all bars as starting points and calculate area of all
rectangles starting with every bar. Finally return maximum of all possible area.
time : O(n*n)

*/

/* Stack solution
time : O(n) , since every height is pushed and popped only once, time complexity is O(n)

*/
int maxRectArea(vector<int>&hist ) {
	int n = hist.size() ;
	int maxArea = 0 ;
	int curArea  ;
	stack<int>s ;
	int poppedHgt ;
	int i = 0 ;
	while ( i < n ) {
		if (s.empty() || hist[s.top()] <= hist[i]) {
			s.push(i) ; i++ ;
		}
		else {
			poppedHgt = hist[s.top()] ; s.pop() ;
			if ( s.empty() ) curArea = poppedHgt * i ;
			else curArea = poppedHgt * (i - 1 - s.top() ) ;
			maxArea = max(curArea , maxArea) ;
		}
	}
	while (!s.empty()) {
		poppedHgt = hist[s.top()] ; s.pop() ;
		if (s.empty() ) curArea = poppedHgt * i ;
		else curArea = poppedHgt * (i - 1 - s.top() ) ;
		maxArea = max(curArea , maxArea) ;
	}
	return maxArea ;

}





signed main () {
	vector<int>a = {6, 2, 5, 4, 5, 1, 6} ;

	cout << maxRectArea(a) << endl ;

	return 0 ;
}