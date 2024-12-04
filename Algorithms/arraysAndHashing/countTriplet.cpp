/*Given an array of distinct integers. The task is to count all the triplets such that sum of two 
elements equals the third element. If there is no such triplet , print -1 . 

Approach : We'll use two pointer technique to solve this problem  
time : O(n*n) ,space : O(1) 


*/


#include <bits/stdc++.h>
using namespace std;

int countTriplets(int A[] , int n ) {
    int count = 0 ; int j ,k ;
    sort(A , A+n) ; 
    for(int i = n-1 ; i >=2 ; --i ) {
        j = 0 ; k = i-1 ; 
        while (j < k ) {
            if ( A[j] + A[k] == A[i]) {
                count++ ; 
                j++ ; k-- ; 
            }
            else if( A[j] + A[k] < A[i]) j++ ; 
            else k-- ; 
        }
    }
    return (count == 0 ) ? -1 : count ; 
}

signed main() {

    int A[] = {1 ,5 ,3 ,2}; 
    int n = sizeof(A)/sizeof(int) ;     
    cout << "Total triplet : " << countTriplets(A,  n ) << endl;

	return 0;
}