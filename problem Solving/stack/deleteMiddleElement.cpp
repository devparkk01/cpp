
/*
Given a stack with push(), pop(), empty() operations, delete the middle of the stack without
using any additional data structure.
Middle: ceil(size_of_stack/2.0)
*/


// i is used to track the position of elements
void util(stack<int>&s , int mid , int &i ) {
	if ( !s.empty()) {
		int x = s.top() ;
		s.pop() ;
		util(s , mid, i) ;
		i++ ;
		if ( i == mid) return ;
		else s.push(x) ;
	}
}
void deleteMid(stack<int>&s, int sizeOfStack)
{
	int i = 0 ; int mid = (sizeOfStack + 1 ) / 2 ;
	util(s , mid , i  ) ;
}
