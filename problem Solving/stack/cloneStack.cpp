/* Given elements of a stack, clone the stack without using extra space.

*/

void clonestack(stack<int> st, stack<int>& cloned)
{
	if (!st.empty() ) {
		int x = st.top() ;
		st.pop() ;
		clonestack(st , cloned) ;
		cloned.push(x) ;
	}
}