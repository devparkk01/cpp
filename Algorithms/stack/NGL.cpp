/* given an array , find the next greater element to the left of each element of the array .

approach is same as NGR
*/



vector<long long> nextGreaterLeft(vector<long long> arr, int n) {
	vector<ll>ans ;  ans.reserve(n) ;
	stack<ll>s ;

	//start iterating from the beginning of the array
	for (int i = 0; i < n  ; ++i) {
		if (s.empty()) ans.push_back(-1) ;
		// top of the stack stores the next greater element to the left
		else if ( s.top() > arr[i]) ans.push_back(s.top() ) ;
		else {
			// keep popping until top of the stack is greater than arr[i]
			while ( !s.empty() && s.top() <= arr[i]) {
				s.pop() ;
			}
			// there is no greater element to the left
			if ( s.empty()) ans.push_back(-1) ;
			// top of the stack is the next greater element to the left
			else ans.push_back(s.top()) ;

		}
		s.push(arr[i]) ;// push the current element into the stack
	}
	return ans ;

}