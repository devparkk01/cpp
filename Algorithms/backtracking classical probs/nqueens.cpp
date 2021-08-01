/* The n queen is the problem of placing N chess queens on an N*N chessboard  so that
no two queens attack each other .


https://practice.geeksforgeeks.org/problems/n-queen-problem0315/1
*/


#include<bits/stdc++.h>
#define endl '\n'
using namespace std ;

class Solution {
public:
	vector<vector<int>> nQueen(int n) {
		vector<int>curPath(n , -1) ;
		vector<vector<int>>ans ;
		solve(0 , n, curPath , ans ) ;

		return ans ;
	}

	void solve(int i , int n , vector<int>&curPath , vector<vector<int>>&ans) {

		if (i == n ) {
			vector<int>temp(curPath.begin() , curPath.end()) ;
			for (int &x : temp ) x++ ;
			ans.push_back(temp) ;
			return ;
		}

		for (int j = 0 ; j < n ; ++j ) {
			if (stable(i , j , curPath)) {
				curPath[i] = j ;
				solve(i + 1 , n , curPath , ans ) ;
				curPath[i] = -1 ;

			}
		}
	}

	bool stable(int i , int j , vector<int>&curPath) {
		for (int k = 0 ; k < i ; ++k) {
			if (curPath[k] == j ) return false ;
			if (abs(i - k ) == abs(j - curPath[k])) return false ;
		}
		return true ;
	}


};
