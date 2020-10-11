/*
First few catalan numbers =  1, 1, 2, 5, 14, 42, 132, 429, 1430 
time : O(n*n) ,space: O(n)
*/

/* We don't have boost/multiprecision/cpp_int.hpp library on our machine . So don't run it. 
*/
#include<bits/stdc++.h>
#include<boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int ; 

int main(){

    vector<cpp_int>c(101) ; 
    c[0] = 1 ; 
    for(int i = 1 ; i <=100 ; ++i ) {
        for(int j = 0 ; j < i ; ++j ) {
            c[i] += (c[j] * c[i-1-j]) ; 
        }
    }
    
    int t;  cin >>t ; 
    while(t-- ) {
        int n  ; cin >> n; 
        cout << c[n] << endl; 
    }
    
    return 0;
}