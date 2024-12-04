/*Given two sorted arrays, the task is to merge them in a sorted manner. Don't use extra space ,i.e,
space : O(1) . 
*/


/* first technique 
 time : O(m *n ) ,space : O(1 )
*/

#include<iostream>
#include<algorithm>

using namespace std ; 

void sorted (int b[] , int m); //
void mergeOne ( int a[] , int n , int b[] , int m ) {
	int i = 0 ; // i for traversing a[] .
	while (i < n ) {
		if ( a[i] > b[0]) {
			swap(a[i], b[0]) ;
			sorted (b, m) ; 
			i++ ; 
		}
		else i++ ; 	
	}
}

void sorted  (int b[] , int m) {
	int i =0 ; 
	while (i + 1 < m && b[i] > b[i+1] ) {// b[i+1] should not go out of bounds. 
		swap(b[i] ,b[i+1]) ;
		i++ ; 
	}
}


/* second technique 
Also called gap algorithm  

*/ 
void mergeTwo (int a[] ,int b[] ,int n , int m  ) {
    int gap = ( n + m + 1  ) / 2; 
    while (gap ) {
        int i = 0 , j = i + gap ; 
        while ( j < n) {
            if ( a[i] > a[j]) 
                swap(a[i] , a[j]) ;
            i++ ;j++ ; 
        }
        while ( i < n && j < m+n ) {
            if (a[i] > b[j-n])
                swap(a[i] , b[j-n]) ; 
            i++ ; j++ ; 
        }
        while ( j < m+n ) {
            if ( b[i-n] > b[j-n]) 
                swap(b[i-n] , b[j-n]) ; 
            i++ ; j++ ; 
        }
        gap = ( gap == 1 ) ? 0 : (gap +1 ) / 2; 
    }
}

/* Third technique * time : O(nlogn + mlogm ) ,space : O(1) */


void mergeThree(int a[] , int b[] , int n , int m ) {
	int i = n-1 ; int j = 0 ; 
	while (  i >= 0 && j < m ) {
		if ( a[i] > b[j]) {
			swap(a[i] , b[j]) ;
			i-- ; j++ ;
		}
		else break ; 
	}
	sort(a , a+n) ; sort(b , b+m) ;  
	
}



int main () {
	int a[] = {2 ,7 , 8} ; int n = sizeof(a) /sizeof(int) ;
	int b[] = {3, 5 } ; int m = sizeof (b) /sizeof(int) ; 
	mergeTwo(a , b, n , m) ; 
	for (int i = 0 ; i < n ; ++i) 
		cout << a[i] << " " ;
	cout << endl; 
	for (int i = 0 ; i < m ; ++i) 
		cout << b[i] << " " ;
	cout << endl; 

	return 0 ; 
}