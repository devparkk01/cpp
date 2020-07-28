#include<iostream>
#include<vector>
#include<unordered_map>
#include<ctime>
#define endl '\n'

using namespace std ; 

//  time : O(2^n) space : O(1)
int fib_typical (int n ) {
    if ( n== 1) return 0 ; 
    if (n == 2) return 1 ; 
    else {
        return fib_typical(n-1) + fib_typical(n-2) ; 
    }
}

//  using memoization , in memoization we store the values of function calls , for later use .
//  we can use unordered_map as well as vector for  storing memoized values . 


// time  : O(n) and space O(n)
int fib (int n , unordered_map<int , int > &mem) {
    if (n == 1 || n== 2) return n-1 ; 
    if ( mem.find(n) == mem.end()) {
        mem[n] = fib(n-1,mem) + fib(n-2 , mem) ; 
        return mem[n] ; 
    }
    else 
        return mem[n] ; 
    
}


// time : O(n) and space O(n)
int fib_iter (int n ) {
    vector<int>mem ;  mem.reserve(n+1) ;
    mem[1] = 0 ; mem[2] = 1 ; 
    for (int i = 3 ; i <= n ; ++i ) {
        mem[i] = mem[i-1] + mem[i-2] ; 
    }
    return mem[n] ; 
}

// time : O(n) and space O(1)
int fib_best (int n ) {
    int first = 0 ; int second = 1 ; 
    int i = 3 ;
    while ( i <= n) {
        int temp = second ; 
        second += first ; 
        first = temp ; 
        i++ ; 
    }
    return second ; 
}

int main () {
    unordered_map<int ,int>mem ;

    cout << fib(10 , mem ) << endl; 
    cout << fib_iter(10) << endl; 
    cout << fib_best(40) << endl; 
    return 0 ; 

}