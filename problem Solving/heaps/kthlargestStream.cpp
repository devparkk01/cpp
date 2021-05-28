/*
Given an input stream arr[] of n integers. Find the Kth largest element for each element in
the stream and  if the Kth element doesn't exist, return -1.


k = 4, n = 6
arr[] = {1, 2, 3, 4, 5, 6}
output : -1 -1 -1 1 2 3

time : O(n log k )
*/

vector<int> kthLargest(int k, int arr[], int n) {
	vector<int>ans(n , -1 ) ;
	priority_queue<int, vector<int> , greater<int>>pq ;
	for (int i = 0 ; i < k ; ++i) pq.push(arr[i]) ;

	ans[k - 1 ] = pq.top() ;

	for (int i = k ; i < n ; ++i ) {
		int top = pq.top() ;
		if (arr[i] > top )  {
			pq.pop() ; pq.push(arr[i]) ;
		}
		ans[i] = pq.top() ;
	}
	return ans;


}