/*Given a matrix mat[][] of size N x M, where every row and column is sorted in increasing order,
and a number X is given. The task is to find whether element X is present in the matrix or not.

*/

#include<bits/stdc++.h>
using namespace std ;
#define endl '\n'

// time : O(N + M )

int matSearch(vector<vector<int>>&mat , int N , int M , int X ) {
	int i = 0 , j = M - 1  ;
	while (i < N && j >= 0) {
		if (mat[i][j] == X) return 1 ;
		else if ( mat[i][j] < X) i++ ;
		else if ( mat[i][j] > X ) j-- ;
	}
	return 0 ;
}

signed main() {
	vector<vector<int>>mat = { {10, 20, 30, 40},
		{15, 25, 35, 45},
		{27, 29, 37, 48},
		{32, 33, 39, 50}
	};

	int N = mat.size() ;
	int M = mat[0].size() ;
	int X = 32 ;
	cout << matSearch(mat , N , M , X) ;
	return 0 ;

}