#include<iostream>
#define endl '\n'

using namespace std ; 

// iterative approach 
int binomialCoeff (int n , int k ) {
    int **coeff = new int*[n+1] ; 
    for (int i = 1 ; i  <= n ; ++i ) {
        coeff[i] = new int [k+1] ; 
    }
    for (int i= 1 ;i <= n; ++i ) {
        for (int j = 0 ; j <= i && j <= k ; ++j ) {
            if (j == i || j == 0 ) {
                coeff[i][j] = 1 ;
            }
            else {
                coeff[i][j] = coeff[i-1][j] + coeff[i-1][j-1] ; 
            }
        }
    }
    return coeff[n][k] ; 
}

// recursive approach 

int binomialCoeffRecur (int n , int k , int ** coeff) {
    if (coeff[n][k] == -1 ) {
        if (k == n || k == 0) {
            coeff[n][k] = 1 ; 
        }
        else {
            coeff[n][k] = binomialCoeffRecur(n- 1 , k , coeff) + binomialCoeffRecur(n-1 , k-1 , coeff) ; 
        }
    }
    return coeff[n][k] ; 
}
/*
Both has time complexity of O(n * k ) and space complexity of O(n * k  ) 

*/



int main () {
    int n , k ; 
    cout << "Enter n and k : " << endl;  
    cin >> n  >> k ; 
    cout << binomialCoeff(n  , k ) << endl; 

    return 0 ;

}