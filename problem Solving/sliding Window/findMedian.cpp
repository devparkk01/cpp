/*Given an array , a[] , and an integer k , the task is to find the median of each window 
of size k . 

naive approach takes O(n*klog k ) time 
with sliding window technique it takes O(n * k ) time . 
*/

#include <bits/stdc++.h>
using namespace std;


/* time : O(n*k) , space : O(k) */ 

void searchAndModify(int win[] , int k , int rem , int ins ) {
    int low = 0 ; int high = k-1 ; int mid ; 
    while( low <= high ) {
        mid =  (low + high )  /2 ; 
        if ( rem == win[mid]) {
            break ; // mid is the index we are looking for
        }
        else if ( rem > win[mid]) {
            low = mid+1 ; 
        }
        else high = mid-1 ; 
    }
    win[mid] = ins ; 
    if ( rem > ins) {
        int i = mid ; 
        while ( i-1 >= 0 && win[i] < win[i-1]) {
            swap(win[i] , win[i-1]) ; i-- ; 
        }
    }
    else  {
        int i = mid ; 
        while ( i+1 <k && win[i] > win[i+1 ]) {
            swap(win[i] ,win[i+1]) ; i++ ; 
        }
    }
    
}

void findMedian(int a[] , int n , int k ) {
    int win[k] ; // window of size k 
    for (int i = 0 ; i < k ; ++i ) win[i] = a[i] ; 
    sort(win , win+k) ; 
	
	(k % 2 ) ? cout << win[k/2] << " " : cout << (win[k/2] + win[k/2 -1 ] ) /2.0 << " " ; 

    for (int i = k ; i < n ; ++i ) {
        int rem = a[i-k] ; // element to be removed from the window 
        int ins = a[i] ;  // element to be inserted into the window 
        searchAndModify(win , k , rem , ins) ; 
		(k % 2 ) ? cout << win[k/2] << " " : cout << (win[k/2] + win[k/2 -1 ] ) /2.0 << " " ; 
    }
    
}




signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL ) ; 
    
    int a[] = {2 ,1 , 0 , 5, -1, 9 } ; int n = sizeof ( a) /sizeof(int) ; 
    int k = 4   ; 
    findMedian(a , n, k  )  ; 

    
    return 0;
}