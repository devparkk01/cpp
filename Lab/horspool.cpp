#include<iostream>
#include<string>
using namespace std; 


int indexOf (int * st , char c) {
    if ( c != ' ') {
        return c - 'A' ; 
    }
    return 26 ; 
}

void shiftTable (string p , int *st) {
    for (int i  = 0  ; i< 27 ; ++i ) {
        st[i] = p.length() ; 
    }

    for (int j = 0 ; j < p.length() - 1 ; ++j) {
        st[indexOf(st , p[j])] = p.length() - 1 - j ;
    }

}

int horspool (string s , string p ) {
    int n = s.length() ; 
    int m = p.length() ; 
    int * st = new int[27] ;
    shiftTable(p , st) ; 
    
    int i = m-1 ; 
    int countC = 0 ,countS = 0 ; 
    while ( i <= n-1) {
        int k = 0 ;
        while ( k <= m-1 && p[m-1-k] == s[i-k]) {
            k++ ; 
            countC++ ; 
        }
        if ( k == m ) {
            cout << "No of comparisons : " << countC << endl; 
            cout << "No of shifting : " << countS << endl ;
            return i-m+1 ; 
        }
        else {
            i  = i + st[indexOf(st , s[i-k])] ; 
            countC++ ; countS++  ; 
        }
    }
    return -1 ; 
}


int main () {
    string s  , p ;
    cout << "Enter main string : " << endl ;
    getline(cin , s ) ; 
    cout << "Enter pattern string : "  << endl ;
    getline(cin , p ) ; 
    cout << horspool(s , p ) ; 


    return 0 ; 
}