/*Given a sorted array Arr of size N and a number X, you need to find the number of
 occurrences of X in Arr.

*/
#include<iostream>
#include<vector>
using namespace std;  

int firstOccurence(vector<int>&a , int x ) {
	int low = 0 ; int high = a.size() - 1; 
	int ans = -1 ; int mid ;
	while (low <= high ) {
		mid = low + (high - low )/ 2 ; 
		if (x == a[mid] ) {
			ans= mid ; 
			high = mid - 1 ;
		}
		else if ( x < a[mid ] ) 
			high = mid - 1; 
		else if (x > a[mid ]) 
			low = mid + 1 ; 
	}
	return ans ; 
}

int lastOccurence(vector<int>&a , int x ) {
	int low = 0 , high = a.size() - 1 ; 
	int ans = -1 , mid ; 
	while (low <= high ) {
		mid = low + (high - low) /2 ; 
		if ( x == a[mid]) {
			ans = mid ; 
			low = mid + 1 ; 
		}
		else if( x < a[mid]) 
			high = mid - 1; 
		else if ( x > a[mid]) 
			low = mid + 1 ; 
	}
	return ans ; 
}


int frequency (vector<int> &a , int x ) {
	int first = firstOccurence(a ,x );  
	int last = lastOccurence (a , x ) ; 
	if ( first == last == -1 ) return 0 ;
	else return last - first + 1 ; 
}

signed main () {
	vector<int>a = {2 ,3 ,4 , 4 , 4  ,5 ,7, 11 }; 
	int x = 6 ; 
	cout << frequency(a , x ) ; 
	return 0 ; 
}