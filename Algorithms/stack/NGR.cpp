/*  Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element on the
right side of x in the array. Elements for which no greater element exist, consider
 next greater element as -1.

approach 1 : use two for loops , time : O(n *n )
approach 2 : use stack , time : O(n) , space : O(n)

*/


vector<long long> nextLargerElement(vector<long long> arr, int n) {
	vector<ll>ans ;  ans.reserve(n) ;
	stack<ll>s ;

	//start iterating from the end of the array
	for (int i = n - 1; i >= 0  ; --i) {
		if (s.empty()) ans.push_back(-1) ;
		// top of the stack stores the next greater element to the right
		else if ( s.top() > arr[i]) ans.push_back(s.top() ) ;
		else {
			// keep popping until top of the stack is greater than arr[i]
			while ( !s.empty() && s.top() <= arr[i]) {
				s.pop() ;
			}
			// there is no greater element to the right
			if ( s.empty()) ans.push_back(-1) ;
			// top of the stack is the next greater element to the right
			else ans.push_back(s.top()) ;

		}
		s.push(arr[i]) ;// push the current element into the stack
	}
	// reverse the final answer
	reverse(ans.begin() , ans.end()) ;
	return ans ;


}