/*  Given an integer array. The task is to find the maximum of the minimum of every window
 size in the array.
Note: Window size varies from 1 to the size of the Array.

https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/

*/



vector <int> maxOfMin(int arr[], int n)
{
	// Your code here
	int nsl[n] , nsr[n] ;
	stack<int>s  , ss   ;

	for (int i = 0 ; i < n ; ++i ) {
		if ( s.empty()) nsl[i] = -1 ;
		else if ( arr[i] > arr[s.top()] ) {
			nsl[i] = s.top() ;
		}
		else {
			while (!s.empty() && arr[i] <= arr[s.top()]) s.pop() ;
			if ( s.empty()) nsl[i] = -1 ;
			else nsl[i] = s.top() ;
		}
		s.push(i) ;
	}
	for (int i = n - 1 ; i >= 0 ; --i) {
		if ( ss.empty()) nsr[i] = n ;
		else if ( arr[i] > arr[ss.top()]) nsr[i] = ss.top() ;
		else {
			while (!ss.empty() && arr[i] <= arr[ss.top()]) ss.pop() ;
			if (ss.empty()) nsr[i] = n ;
			else nsr[i] = ss.top() ;
		}
		ss.push(i) ;
	}
	vector<int>ans(n + 1 ) ;

	int window ;
	for (int i = 0 ; i < n ; ++i ) {
		window = nsr[i] - nsl[i] - 1 ;
		ans[window] = max(ans[window] , arr[i]) ;
	}

	for (int i = n - 1 ; i >= 1 ; --i ) ans[i] = max(ans[i] , ans[i + 1 ]) ;

	ans.erase(ans.begin()) ;


	return ans  ;



}