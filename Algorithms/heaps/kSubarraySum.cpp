/*
Given an integer array arr of size N and two integers K and M, the task is to
 find M largest sums of K sized subarrays.

of course we will be using sliding window + priority queue to solve this problem



*/


#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(0) ; cin.tie(0) ;
#define endl '\n'
using namespace std;

int main()
{
	fastio ;
	int t; cin >> t;
	while (t-- ) {
		int n , k , m ;
		cin >> n >> k >> m ;
		int a[n] ; for (int i = 0 ; i < n ; ++i) cin >> a[i] ;
		int sum = 0 ;
		for (int i = 0 ; i < k ; ++i ) sum += a[i] ;

		priority_queue<int , vector<int> > pq;
		pq.push(sum) ;


		for (int i = k ; i < n ; ++i ) {
			sum += ( a[i] - a[i - k ]) ;
			pq.push(sum) ;
		}

		while (m--) {
			cout << pq.top() << " " ;
			pq.pop() ;
		}
		cout << endl;

	}
	return 0;
}