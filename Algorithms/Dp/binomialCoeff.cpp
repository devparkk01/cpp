#include<bits/stdc++.h>
#define endl '\n'

using namespace std ; 

// bottom up approach 
int binomialCoeff(int n , int r ) {
    int c[n+1][r+1] ; 

    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 0 ; j <= min(i , r ) ; ++j ) {
            if ( j == 0 || j == i ) c[i][j] = 1 ; 
            else 
                c[i][j]= c[i-1][j-1] + c[i-1][j] ; 
        }
    }
    return c[n][r] ; 

}


// Top down approach 
// int binomialCoeffUtil(int n , int r , vector<vector<int>>&mem ) {
//     if ( n == r || r == 0) return 1 ; 
//     if (mem[n][r] != 0 ) return mem[n][r] ; 
//     else {
//         mem[n][r] = binomialCoeffUtil(n-1 , r-1 , mem) + binomialCoeffUtil(n-1 , r, mem) ; 
//         return mem[n][r] ; 
//     }
// }

// int binomialCoeff(int n , int r ) {
//     vector<vector<int>>mem(n+1 , vector<int>(r+1)) ; 
//     return binomialCoeffUtil(n , r , mem ) ; 
// }


// Both has time complexity of O(n*r) and space complexity of O(n*r)

/* 
space optimized approach (pascal triangle approach) , time : O(n*r) , space : O(r) 
*/

// int ncr(int n , int r ) {
//     int c[r+1] ;
//     memset(c , 0 , sizeof(c)) ; 
//     c[0] = 1 ;
//     for(int i = 1 ; i <= n ; ++i ){
//         for(int j = r ; j > 0 ; --j ) {
//             c[j] = (c[j] +c[j-1]); 
//         }
//     }
//     return c[r] ; 

// }



int main () {
    int n = 10 ; int r = 5 ; 
    cout << binomialCoeff(n,r) << endl;  
    cout << ncr(n , r) << endl; 
    return 0 ;
}