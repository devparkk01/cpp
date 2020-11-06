/*Given a sorted array and a value x, the floor of x is the largest element in array 
smaller than or equal to x.


Given a sorted array and a value x,find the ceil of x ,  the ceiling of x is the smallest 
element in array  greater than or equal to x

Return their indices 

*/

#include<iostream>
#define fastio ios_base::sync_with_stdio(false) ; cin.tie(NULL ); 
using namespace std;

int getFloor(int a[] , int n , int k ) {
    int low = 0 , high = n-1 ; 
    int mid ; int ans = -1 ; 
    while ( low <= high ) {
        mid = low + (high - low ) /2 ; 
        if (a[mid] == k ) return mid ; 
        else if ( a[mid] < k ) {
            ans = mid ; 
            low = mid + 1; 
        }
        else if (a[mid] > k ) 
            high = mid - 1 ; 
    }
    return ans; 
}

int getCeil(int a[] , int n , int k ) {
	int low = 0 , high = n-1 ; 
	int mid , ans = -1 ; 
	while (low <= high ) {
		mid = low + (high - low ) /2 ; 
		if (a[mid] == k) return mid ; 
		else if (a[mid] > k ) {
			ans = mid ; 
			high = mid- 1; 
		}
		else if(a[mid] <  k) 
			low = mid + 1 ; 
	}
	return ans ; 
}

signed main(){
	int a[] = {1 , 2, 4, 5, 6, 7, 10 , 12} ; 
	int n = sizeof(a)/sizeof(int) ; 
	int k = 11 ; 
	cout << "Floor of 10 : " << getFloor(a , n , k ) << endl; 
	cout << "Celi of 10 :" << getCeil(a , n , k ) << endl; 
	return 0 ; 
}
