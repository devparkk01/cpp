
/*
Given a stack with push(), pop(), empty() operations, delete the middle of the stack without
using any additional data structure.
Middle: ceil(size_of_stack/2.0)



Efficient approach: 
we can recursion here. Recursion space is same as having another stack. 
Keep popping the elements from the top of the stack while keeping track of the position of 
the elements. When the current position becomes equal to middle, stop the recursive step. At the 
end of each recursive call, push the popped element. 
*/


// i is used to track the position of elements
void util(stack<int>&s, int i , int mid) {
	int e = s.top(); 
	s.pop();
	
	if ( i == mid) return;
	else {
		util(s, i + 1, mid );
	}
	s.push(e);
}

//Function to delete middle element of a stack.
void deleteMid(stack<int>&s, int sizeOfStack){
	int i = 0, mid = (sizeOfStack / 2); 
	util(s, i, mid);
}