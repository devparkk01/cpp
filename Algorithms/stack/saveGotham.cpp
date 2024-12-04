/* https://practice.geeksforgeeks.org/problems/save-gotham1222/1/?category[]=Stack&category[]=Stack&page=1&query=category[]Stackpage1category[]Stack#


*/



int mod = 1000000001 ;
int save_gotham(int arr[], int n)
{
	stack<int>s ;
	int ans = 0 ;

	for (int i = n - 1 ; i >= 0 ; --i) {
		if ( s.empty()) ans += 0 ;
		else if (arr[i] < s.top()) ans = (ans + s.top() ) % mod ;
		else {
			while ( !s.empty() && arr[i] >= s.top()) s.pop() ;
			if ( s.empty()) ans += 0 ;
			else ans = (ans + s.top() ) % mod ;
		}
		// vvi
		s.push(arr[i]) ;
	}
	return ans ;

}