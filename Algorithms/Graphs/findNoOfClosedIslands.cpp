/* https://practice.geeksforgeeks.org/problems/find-number-of-closed-islands/1#

approach discussed down below
*/

class Solution {
public:
	int closedIslands(vector<vector<int>>& matrix, int N, int M) {

		// top row filling 0
		for (int j = 0 ; j  < M ; ++j) {
			if (matrix[0][j] == 1 ) {
				dfs(matrix , 0 , j , N , M ) ;
			}
		}
		// bottom row filling o
		for (int j = 0 ; j < M ; ++j) {
			if (matrix[N - 1 ][j] == 1 ) dfs(matrix, N - 1 , j , N , M) ;
		}
		// first column filling 0
		for (int i = 0 ; i < N ; ++i) {
			if (matrix[i][0] == 1) dfs(matrix , i , 0 , N , M) ;
		}
		// last column filling 0
		for (int i = 0 ; i < N ; ++i) {
			if (matrix[i][ M - 1] == 1 ) dfs(matrix, i , M - 1 , N , M ) ;
		}

		int count = 0 ;
		// 	counting no of islands
		for (int i = 0 ; i < N ; ++i) {
			for (int j = 0 ; j < M ; ++j)  {
				if (matrix[i][j] == 1 )  {
					count++ ;
					dfs(matrix , i , j ,  N , M ) ;
				}
			}
		}
		return count  ;

	}


	void dfs(vector<vector<int>>&matrix , int i , int j , int N , int M ) {
		matrix[i][j] = 0 ;

		if (safe(i + 1, j, N, M) && matrix[i + 1][j] == 1 ) dfs(matrix , i + 1 , j , N , M) ;
		if (safe(i - 1, j, N, M) && matrix[i - 1][j] == 1 ) dfs(matrix , i - 1 , j , N , M) ;
		if (safe(i , j + 1, N, M) && matrix[i][j + 1] == 1)dfs(matrix , i , j + 1 , N , M ) ;
		if (safe(i , j - 1 , N, M) && matrix[i][j - 1 ] == 1 ) dfs(matrix , i , j - 1 , N , M);

	}

	bool safe(int i , int j , int N , int M) {
		if (i < 0 || i >= N || j < 0 || j >= M ) return 0 ;
		return 1 ;
	}

};

/* since we are not supposed to consider 1s that lie on the edges . Therefore we should not also
consider those 1s which are connected to the 1s lying on the edges .
step1 : run dfs on the cell and it's connected cells  if their value is 1  and it's lying on the
edges,change all this connected 1s to Os , so that we don't consider these connected  cells as islands .

step2 : run dfs on every cell and its connected cells if their value is 1 . Count them as island





*/