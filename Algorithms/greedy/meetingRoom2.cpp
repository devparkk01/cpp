/*
https://www.interviewbit.com/problems/meeting-rooms/



sort based on start time ,
create a min heap based on end time ,
our answer will be max size of the min heap at any point of time

*/

bool compare(vector<int>&a , vector<int>&b ) {
	if (a[0] < b[0]) return 1 ;
	else return 0 ;
}

int Solution::solve(vector<vector<int> > &A) {
	sort(A.begin() , A.end() , compare ) ;
	priority_queue<int , vector<int> , greater<int>> minheap  ;
	minheap.push(A[0][1]) ;
	int ans = 1 ;
	int n = A.size() ;
	for (int i = 1 ; i <  n ; ++i) {
		int top = minheap.top() ;
		if (A[i][0] >= top) {
			minheap.pop() ;
			minheap.push(A[i][1]) ;
		}
		else {
			minheap.push(A[i][1]) ;
			ans = max(ans , (int)minheap.size() ) ;
		}
	}
	return ans ;

}
