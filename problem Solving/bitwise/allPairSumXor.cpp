/*
 given an array , arr[] , return the xor sum of every possible pair of elements in the arr .
 i.e. return (a1 + a1) ^ (a1 + a2) ^ (a1 + a3) ... ^ (a1 + an ) ^
			 (a2 + a1) ^ (a2 + a2) ^ (a2 + a3) ... ^ (a2 + an ) ^
			 ...

			(an + a1) ^ (an + a2) ^ (an + a3) ... ^ (an + an ) ^
*/


#include<bits/stdc++.h>
using namespace std;


// time : O(n)
int allpairxor(int a[] , int n ) {
	int ans = 0 ;
	for (int i = 0 ; i < n ; ++i ) {
		ans = ans ^ (2 * a[i]) ;
	}
	return ans ;
}


signed main() {
	int a[] = {4 , 3 , 9 , 1 };
	int n = sizeof(a) / sizeof(int ) ;
	cout << allpairxor(a , n ) << endl;

	return 0 ;
}