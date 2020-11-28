/*Write an efficient algorithm that searches for a value in an n* m matrix. This matrix has the
following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

*/
#include<bits/stdc++.h>
using namespace std ;

#define endl '\n'
#define f(i , k , n) for(int i = k ; i < n ; ++i )


/* first solution
We can use the same logic that we did for searching in a row wise and column wise sorted matrix
 time : O(n + m )
*/

/* second solution
create a temporary array which stores the elements of matrix in a sorted way
time : O(log(m *n ))
*/

/*
bool searchMatrix(vector<vector<int>>&matrix , int target ) {
	int n = matrix.size() ;
	if ( n == 0 ) return false ;
	int m = matrix[0].size() ;
	int size = n * m ;
	int temp[size ] ;
	int index = 0 ;

	f(i , 0 , n ) {
		f(j , 0 , m) {
			temp[index++] = matrix[i][j];

		}
	}

	int low = 0 , high = size - 1 ; int mid ;
	while (low <= high ) {
		mid = low + (high - low) / 2 ;
		if ( temp[mid] == target) return true ;
		else if (temp[mid] < target ) low = mid + 1 ;
		else high = mid - 1 ;
	}
	return false ;

}
*/


// time : O(log(n * m )) = O(log m + log n )
// optimal solution
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	int n = matrix.size() ;
	if ( n == 0 ) return false ;
	int m = matrix[0].size() ;

	int low = 0 , high = ( m * n) - 1 ;
	int elem ;
	int mid , row , col ;
	while ( low <= high )  {
		mid = low + ( high - low ) / 2 ;
		row = mid / m ;
		col = mid % m ;
		elem = matrix[row][col] ;
		if ( elem == target) return true ;
		else if ( elem < target ) low = mid + 1 ;
		else if ( elem > target )  high = mid - 1;
	}
	return false ;
}

signed main () {
	vector<vector<int>> matrix = {{1 , 3 , 5 , 7 },
		{10 , 11,  16, 20 } ,
		{23 , 30 , 34 , 50 }
	} ;
	int target = 53 ;
	cout << searchMatrix(matrix , target ) << endl ;

	return 0 ;
}