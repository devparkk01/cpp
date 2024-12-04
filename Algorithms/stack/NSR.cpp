/*
Given an array, for every element print the next smaller element to its right .

approach is same as NSL

time : O(n) , space : O(n)

*/

vector<int> NSR(int n, int a[]) {
	stack<int>s ;
	vector<int>ans ; ans.reserve(n ) ;

	for (int i = n - 1 ; i >= 0 ; --i) {
		if ( s.empty()) ans.push_back(-1) ;
		else if ( a[i] > s.top()) ans.push_back(s.top()) ;
		else {
			while (!s.empty() && a[i] <= s.top()) s.pop() ;
			if ( s.empty()) ans.push_back(-1) ;
			else ans.push_back(s.top()) ;
		}
		// vvi step
		s.push(a[i]) ;
	}
	reverse(ans.begin() , ans.end()) ;
}
