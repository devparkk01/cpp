#include<bits/stdc++.h>       // includes STL as well as iostream  

#define endl '\n'       // using macro for  breaking the line  

using namespace std ;


int main () {
    // ios_base::sync_with_stdio(false) ;
    // cin.tie(NULL) ;
    // always include above three lines

    int x ;
    cout << "Enter x : " << "\n" ;
    cin >> x ;
    cout << "Number is : " << x << "\n" ;
    vector<int> vec ;
    vec.reserve(10) ;
    vec.push_back(3) ;
    cout << vec[0] ;

    return 0 ;
}
