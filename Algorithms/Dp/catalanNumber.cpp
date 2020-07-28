/*
First few catalan numbers =  1, 1, 2, 5, 14, 42, 132, 429, 1430 


*/

#include<iostream>
#define endl '\n'

using namespace std ; 

// time complexity O(n^2) and space complexity : O(n)
int catalan (int n ) {
    int * cat = new int[n+1] ;
    cat[0] = 1 ; cat[1] = 1; 

    for (int i = 2 ; i <= n ; ++i) {
        cat[i] = 0 ; 
        for (int j = 0 ; j < i ; ++j ) {
            cat[i] += cat[j]* cat[i-1-j] ; 
        }
    }
    return cat[n] ; 

}

int main() {
    cout << "Enter n  : "  ; int n ; 
    cin >> n ;
    cout << catalan (n ) << endl; 

    return 0 ; 
}