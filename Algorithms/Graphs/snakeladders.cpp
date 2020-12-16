/*Given a snake and ladder board of order 5x6, find the minimum number of dice throws(rolls)
 required to reach the destination or last cell (30th cell) from source (1st cell) .

The first line of input contains an integer T denoting the no of test cases.
Then T test cases follow. Each test case contains two lines. The first line of input
contains an integer N denoting the no of ladders and snakes present. Then in the next line
are 2*N space separated values a,b which denotes a ladder or a snake at position 'a' which
takes to a position 'b'.

Approach :  The idea is to use bfs .
time : O(N) , size of the board

*/



#include<bits/stdc++.h>
using namespace std ;
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL) ;
#define endl '\n'
#define f(i , k , n ) for(int i = k ; i < n ; ++i )
#define ip pair<int , int>
#define pb push_back

int solve(vector<int>&moves , int N ) {
	queue<ip>q ; q.push({1 , 0 }) ;
	vector<bool>visited(N + 1 ) ;
	visited[1] = 1 ;

	ip temp ; int  pos , rolls ;
	while (!q.empty() ) {
		temp = q.front() ; q.pop() ;
		pos = temp.first ; rolls = temp.second ;

		if ( pos == N) return rolls ;
		f(i , 1 , 7) {
			if ( !visited[pos + i ] && pos + i <= N ) {
				int nextpos = (moves[pos + i] != -1 ) ? moves[pos + i] : pos + i ;
				if (!visited[nextpos]) {
					q.push({nextpos , rolls + 1 }) ;
					visited[nextpos] = 1 ;
					visited[pos + i ] = 1 ;
				}
			}
		}

	}
	return rolls ;
}

int main()
{
	fastio ; int N = 30 ;
	int t; cin >> t;
	while (t--) {
		vector<int>moves(N + 1 , -1) ;
		int n; cin >> n;
		int a , b ;
		f(i , 0 , n ) {
			cin >> a >> b ;
			moves[a] = b ;
		}
		cout << solve(moves , N ) << endl ;
	}

	return 0;
}



