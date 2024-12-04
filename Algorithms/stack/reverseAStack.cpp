#include <stack>
#include<iostream>
using namespace std;
/*
if using stl and no extra space : time : O(n * n )
if not using stl (stl implemented using linked list ) : time : O(n)

*/

void pushBottom(stack<int>&s , int e ) {
	if (s.empty()) s.push(e) ;
	else {
		int top = s.top()  ; s.pop() ;
		pushBottom(s , e) ;
		s.push(top) ;
	}
}

void reverse(stack<int>&s ) {
	if (s.empty()) return ;
	else {
		int top = s.top() ; s.pop() ;
		reverse(s) ;
		pushBottom(s , top) ;
	}
}

void print(stack<int>s) {
	if (!s.empty()) {
		int top = s.top() ;
		s.pop()  ;
		cout << top << " " ;
		print(s) ;
		s.push(top) ;
	}
}

int main() {
	stack<int>s ;
	s.push(2) ; s.push(3) ; s.push(4) ;
	print(s) ;
	cout << endl;
	reverse(s) ;
	print(s) ;

	return 0 ;
}

