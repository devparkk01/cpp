/*Given 2 integers A and B and an array of integars C of size N.

Element C[i] represents length of ith board.

You have to paint all N boards [C0, C1, C2, C3 … CN-1]. There are A painters available and each
of them takes B units of time to paint 1 unit of board.

Calculate and return minimum time required to paint all boards under the constraints
that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

This question is same as allocate min no of pages problem

*/

#include<bits/stdc++.h>
using namespace std ;

bool isValid(int A , vector<int>&C , int n , int maxLen) {
    int painter = 1 ;
    int sum = 0 ;
    for (int i = 0 ; i < n ; ++i ) {
        if (C[i] > maxLen) return false;
        else if (sum + C[i] > maxLen ) {
            painter++ ;
            sum = C[i] ;
            if ( painter > A ) return false ;
        }
        else sum += C[i] ;
    }
    return true ;
}

int paint(int A, int B, vector<int> &C) {
    int n  = C.size() ;
    int low = 0 ; int high = accumulate(C.begin() , C.end() , 0 ) ;
    long mid ; long res = high ;
    while (low <= high ) {
        mid = low + (high - low ) / 2 ;
        if (isValid(A , C , n , mid)) {
            res = mid ;
            high = mid - 1 ;
        }
        else low = mid + 1 ;
    }
    int mod = 10000003 ;
    return ( res * B) % mod ;

}



