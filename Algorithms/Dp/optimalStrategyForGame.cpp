/*
You are given an array A of size N. The array contains integers and is of length.
The elements of the array represent N coin of values V1, V2, ....Vn.
 You play against an opponent in an alternating way.
In each turn, a player selects either the first or last coin from the row, removes it from
the row permanently, and receives the value of the coin.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.


time : O(n * n ) , space : O(n *n )
*/


#include<bits/stdc++.h>
using namespace std ;


int mem[1001][1001] ;

// returns maximum value user can get from index 'start' to 'end'
int util(int arr[] , int start , int end ) {
	// there is only one coin
	if ( start == end) return arr[start] ;
	// there are only 2 coins
	if ( start + 1 == end ) return max(arr[start] ,  arr[end]) ;

	if ( mem[start][end] != -1 ) return mem[start][end] ;
	// if user selects the first coin
	int x = arr[start] + min(util(arr, start + 2 , end), util(arr, start + 1, end - 1 )) ;
	// if user selects the  last coin
	int y = arr[end] + min(util(arr, start + 1 , end - 1) , util(arr , start , end - 2)) ;

	return mem[start][end] = max(x , y )  ;
}


long long maximumAmount(int arr[], int n)
{
	memset(mem , -1 , sizeof(mem)) ;
	return util(arr  , 0 , n - 1 )  ;
}

signed main() {
	int arr[] = {8, 15, 3, 7} ;
	int n = sizeof(arr) / sizeof(int ) ;
	cout << maximumAmount(arr , n ) << endl;
	return 0 ;

}

