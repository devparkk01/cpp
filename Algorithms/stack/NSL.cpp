/*
Given an array, for every element print the next smaller element to its left .
The Next smaller element for an element x is the first smaller element on the
left side of x in the array. Elements for which no smaller element exist, consider
next smaller element as -1.


time : O(n) , space : O(n)
*/

vector<int> NSL(int n, int a[]) {
	stack<int>s ;
	vector<int>ans ; ans.reserve(n ) ;
	for (int i  = 0 ; i < n ; ++i )  {
		if (s.empty()) ans.push_back(-1) ;
		else if ( a[i] > s.top()) {
			ans.push_back(s.top()) ;
		}
		else {
			while (!s.empty() && a[i] <=  s.top()) s.pop() ;
			if (s.empty()) ans.push_back(-1) ;
			else ans.push_back(s.top()) ;
		}
		s.push(a[i]) ;
	}
	return ans;


}