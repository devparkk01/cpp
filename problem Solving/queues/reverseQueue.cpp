/*
reverse a queue . we can simply do it using a temporary stack , but here I will show how to do
it using recursive stack

*/


#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'


void reverseQ(queue<int>&q) {
	if ( !q.empty()) {
		int temp = q.front() ;
		q.pop() ;
		reverseQ(q) ;
		q.push(temp) ;
	}
}

void printQ(queue<int>q) {
	cout << "PRINTING REVERSED QUEUE " << endl;
	while (!q.empty()) {
		cout << q.front() << " " ;
		q.pop() ;
	}
}

signed main() {
	queue<int>q ; q.push(3) ; q.push(55) ; q.push(1) ; q.push(10) ;
	reverseQ(q) ;
	printQ(q) ;
	return 0 ;
}