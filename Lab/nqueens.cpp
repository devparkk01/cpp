#include<iostream>
#include<stdlib.h>
using namespace std ; 

void printSolution (int * x , int n) {
    for(int i = 1 ; i <= n ; ++i) 
        cout << x[i] << "  " ;
}

int PLACE (int * x, int k , int i ) {  // check whether kth queen(x[k]) can be placed in ith column or not 
    for (int j = 1 ; j < k ; ++j) {
        if ( x[j] == i ||  abs(j - k ) == abs(x[j] - i ))
            return 0 ; 
    }
    return 1 ; 
}


void nQueens(int n ) {
    int *x = new int[n+1] ; 
    int k = 1 ; x[k] = 0 ; 
    
    while (k > 0 ) {
        x[k] = x[k] + 1; 

        while (x[k] <= n && !PLACE(x , k , x[k] )){
            x[k] =  x[k] + 1 ; 
        }

        if ( x[k] <= n ) {
            if (k == n ) {
                printSolution(x , n ) ; return ; 

            }
            else 
                k++ ;
                x[k] = 0 ; 
        }

        else {
            k-- ; 
        }


    }
    cout << "No solution exists " << endl; 

}

int main() 
{
    int n ; 
    cout << "Enter n " << endl ; 
    cin >> n ;

    nQueens(n) ; 
    return  0 ;

}