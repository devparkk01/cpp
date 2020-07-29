/*Given an array A of size N, construct a Product Array P (of same size) such that P is equal
to the product of all the elements of A except A[i].
arr= {10 3 5 6 2}
product = {180 600 360 300 900}
*/

#include <iostream>
using namespace std;

/*
l[i]  stores the product of all elements to the left of ith element 
r[i] stores the product of all elements to the right of ith element 

*/

int main() {
	//code
	int t; cin >> t;
	while (t-- ) {
	    int n ; cin >> n ; 
	    int a[n] ; 
	    for (int i = 0 ;i <n ; ++i ) cin >> a[i] ;
	    int l[n] , r[n] ; l[0] = 1; r[n-1] =  1; 
	    for(int i = 1 ; i<n ; ++i ) l[i] = a[i-1] * l[i-1] ; 
	    for (int i= n-2 ; i>=0 ; --i) r[i] = a[i+1] * r[i+1] ; 
	    
	    for (int i = 0 ; i < n ; ++i ) {
	        cout << l[i] * r[i] << " " ; 
	    }
	    cout << endl; 
	}
	return 0;
}