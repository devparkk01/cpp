/*Given a stack, the task is to sort it such that the top of the stack has the greatest element.
time : O(n*n) ,space : O(n) recursive space 

Input:  -3  <--- Top , Output : 30  <--- Top
        14                      18
        18                      14
        -5                      -3
        30                      -5

*/


#include<bits/stdc++.h>
using namespace std ; 

void sortedInsert(stack<int>&stk , int elem ) ; 

void sort(stack<int>&stk) {
	if( !stk.empty()) {
		int top = stk.top() ; 
		stk.pop() ; 
		sort(stk) ; 
		sortedInsert(stk , top ) ; 
	}
}
// used for inserting elements into the stack in sorted fashion . 
void sortedInsert(stack<int>&stk , int elem ) {
	if (stk.empty() || elem >= stk.top() ) 
		stk.push(elem) ;
	else {
		int top = stk.top() ; 
		stk.pop() ; 
		sortedInsert(stk , elem) ; 
		stk.push(top);
	}
}

void printStack(stack<int>& stk ) {
	if (!stk.empty()) {
		int top = stk.top() ; 
		stk.pop() ; 
		cout << top << endl  ;
		printStack(stk) ; 
		stk.push(top) ; 
	}
}


signed main () {
	stack<int>stk ;
	stk.push(10); stk.push(3) ; stk.push(4) ; stk.push(-1) ; 
	cout << "Before sorting : " << endl; 
	printStack(stk) ; 
	sort(stk) ; 
	cout <<"After sorting : " << endl; 
	printStack(stk) ; 

	return 0 ; 
}
